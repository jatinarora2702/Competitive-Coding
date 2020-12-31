#include <bits/stdc++.h>
#define PB push_back
#define FF first
#define SS second

#define ASK 0
#define BID 1
#define MAXDISPLAY 5
#define USECACHE true

#define IOC "I"
#define MKT "M"

#define E1 "404 - Order does not exist\n"
#define E2 "101 - Invalid amendment details\n"
#define E3 "303 - Invalid order details\n"
#define E4 "450 - Action not supported\n"

using namespace std;

const long double INF = 1e10;

typedef long long int lli;

class matcher_exception : public exception {
    public:
        string e;
        matcher_exception(string e_): e (e_) {};
        virtual const char *what() const throw() {
            return e.c_str();
        }
};

typedef struct order_ {
    lli id;
    lli ts;
    lli qty;
    lli pqty;
    int side;
    string sec;
    string type;
    long double price;

    bool operator < (const order_ &ord) const {
        if (price == ord.price) {
            if (ts == ord.ts) {
                return id < ord.id;
            }
            return side == ASK ? (ts < ord.ts) : (ts > ord.ts);
        }
        return price < ord.price;
    }
} order;

typedef struct ordbook_ {
    ordbook_(): last_match_ts(0LL) {};
    set < order > tradeside[2];
    map < long, order > mp;
    lli last_match_ts;
} ordbook;

typedef map < string, ordbook > secbook;

vector < vector < string > > db;
map < lli, secbook > cache;

bool record_comparator (const vector < string > &cmd1, const  vector < string > &cmd2) {
    return stoll(cmd1[2]) < stoll(cmd2[2]);
}

string handle (secbook &sb, vector < string > &cmd);

vector < string > parse (string s) {
    string tok;
    vector < string > v;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    istringstream ss(s);
    while (getline(ss, tok, ',')) {
        v.PB(tok);
    }
    return v;
}

string getprice (long double p) {
    stringstream ss;
    ss << fixed << setprecision(2) << p;
    return ss.str();
}

void adjust_timestamp (vector < string > &cmd, string system_ts) {
    if (cmd.size() == 2) {
        cmd.PB("");
        cmd[2] = cmd[1];
        cmd[1] = "";
    }
    else if (cmd.size() == 3) {     // to handle the position of timestamp in command
        string tmp = cmd[2];
        cmd[2] = cmd[1];
        cmd[1] = tmp;
    }
}

bool isvalid(const order &ord, lli ts) {
    return !(ord.type == IOC && ord.ts <= ts);
}

bool check_details(const order &old_ord, const order &new_ord) {
    bool validity = (old_ord.type == new_ord.type) && (old_ord.sec == new_ord.sec) && (old_ord.side == new_ord.side);
    return validity;
}

// ensuring that implementation details of infinity handling are not exposed on the display.
string printorder(const order &ord) {
    string s = "";
    if (ord.side == ASK) {
        s += ((ord.price == INF) ? "0.0" : getprice(ord.price)) + "," + to_string(ord.qty) + "," + ord.type + "," + to_string(ord.id);
    }
    else {
        s += to_string(ord.id) + "," + ord.type + "," + to_string(ord.qty) + "," + ((ord.price == INF) ? "0.0" : getprice(ord.price));
    }
    return s;
}

string printbook (ordbook &ob) {
    auto &ask = ob.tradeside[ASK];
    auto &bid = ob.tradeside[BID];
    auto it_bid = bid.rbegin();
    auto it_ask = ask.begin();
    int count = 0;
    stringstream ss;
    while (it_bid != bid.rend() && it_ask != ask.end() && count < MAXDISPLAY) {
        if (!isvalid(*it_bid, ob.last_match_ts)) {
            ob.mp.erase(it_bid -> id);
            bid.erase(next(it_bid).base());
            continue;
        }
        if (!isvalid(*it_ask, ob.last_match_ts)) {
            ob.mp.erase(it_ask -> id);
            it_ask = ask.erase(it_ask);
            
            continue;
        }
        ss << it_ask -> sec << "|" << printorder(*it_bid) << "|" << printorder(*it_ask) << endl;
        count++;
        it_bid++;
        it_ask++;
    }
    while(it_bid != bid.rend() && count < MAXDISPLAY) {
        if (!isvalid(*it_bid, ob.last_match_ts)) {
            ob.mp.erase(it_bid -> id);
            bid.erase(next(it_bid).base());
            continue;
        }
        ss << it_bid -> sec << "|" << printorder(*it_bid) << "|" << endl;
        count++;
        it_bid++;
    }
    while(it_ask != ask.end() && count < MAXDISPLAY) {
        if (!isvalid(*it_ask, ob.last_match_ts)) {
            ob.mp.erase(it_ask -> id);
            it_ask = ask.erase(it_ask);
            
            continue;
        }
        ss << it_ask -> sec << "||" << printorder(*it_ask) << endl;
        count++;
        it_ask++;
    }
    return ss.str();
}

string printbook(secbook &sb) {
    stringstream ss;
    for (auto &st : sb) {
        ss << printbook(st.SS);
    }
    return ss.str();
}

string validate (string s, int validation_type) {
    try {
        switch (validation_type) {
            case 3: // security
                if (find_if(s.begin(), s.end(), [](char c) { return !isalpha(c); }) == s.end()) {
                    return s;
                }
                break;
            case 4: // type
                if (s == "I" || s == "M" || s == "L") {
                    return s;
                }
                break;
            case 5: // side
                if (s == "B" || s == "S") {
                    return s;
                }
                break;
            case 6: // price
                if (find_if(s.begin(), s.end(), [](char c) { return !(isdigit(c) || c == '.'); }) == s.end() && stold(s) >= 0.0) {
                    return s;
                }
                break;
            case 7: // quantity
                if (find_if(s.begin(), s.end(), [](char c) { return !(isdigit(c)); }) == s.end() && stoll(s) > 0) {
                    return s;
                }
                break;
        }
    }
    catch (exception &e) {
        throw matcher_exception(E3);
    }
    throw matcher_exception(E3);
}

order makeorder(const vector < string > &cmd) {
    lli tmp;
    order ord;
    try {
        ord.id = stoll(cmd[1]);
        ord.ts = stoll(cmd[2]);
        ord.sec = validate(cmd[3], 3);
        ord.type = validate(cmd[4], 4);
        ord.side = (validate(cmd[5], 5) == "S") ? ASK : BID;
        ord.price = stold(validate(cmd[6], 6));
        ord.qty = stoll(validate(cmd[7], 7));
        ord.pqty = ord.qty;
    }
    catch (matcher_exception e) {
    	throw matcher_exception(cmd[1] + " - Reject - " + e.what());
    }
    return ord;
}

secbook getbook (string timestamp, string sec = "") {
    vector < string > cmd(3);
    lli ts, closest_ts;
    secbook sb;
    ts = stoll(timestamp);
    closest_ts = 0LL;
    if (USECACHE) {
        auto it_cache = cache.upper_bound(ts);
        if (it_cache != cache.begin()) {
            it_cache--;
            closest_ts = it_cache -> first;
            sb = it_cache -> second;
        }
    }
    if (closest_ts != ts) {
        cmd[2] = to_string(closest_ts);
        auto const &it_start = upper_bound(db.begin(), db.end(), cmd, record_comparator);
        cmd[2] = timestamp;
        auto const &it_end = upper_bound(db.begin(), db.end(), cmd, record_comparator);
        for (auto it = it_start ; it != it_end ; it++) {
            if ((*it).size() < 4 || USECACHE || sec.size() == 0 || (*it)[3] == sec) {
                try {
                    handle (sb, *it);
                }
                catch (exception &e) {
                    //cerr << e.what() << endl;
                }
            }
        }
        if (USECACHE) {
            cache[ts] = sb;
        }
    }
    return sb;
}

string add (secbook &sb, order ord) {
    auto &ob = sb[ord.sec];
    auto &st = ob.tradeside[ord.side];
    auto it_mp = ob.mp.find(ord.id);
    
    if (it_mp != ob.mp.end()) {
        auto &old_ord = it_mp -> SS;
        if (isvalid(old_ord, sb[ord.sec].last_match_ts)) {
            throw matcher_exception(to_string(ord.id) + " - Reject - " + E3);
        }
        ob.mp.erase(it_mp);
        st.erase(old_ord);
    }
    if (ord.type == MKT) {
        if (ord.price != 0.0) {
            throw matcher_exception(to_string(ord.id) + " - Reject - " + E3);
        }
        ord.price = (ord.side == ASK ? 0.0 : INF);
    }
    ob.mp[ord.id] = ord;
    st.insert(ord);
    return to_string(ord.id) + " - Accept\n";
}

string amend (secbook &sb, order ord) {
    long double tmp, price_diff;
    lli qty_diff;
    ordbook &ob = sb[ord.sec];
    auto &st = ob.tradeside[ord.side];
    auto it_mp = ob.mp.find(ord.id);
    if (it_mp != ob.mp.end()) {
        auto &old_ord = it_mp -> SS;
        if (isvalid(old_ord, ob.last_match_ts)) {
            if (ord.type == MKT) {
                if (ord.price != 0.0) {
                    throw matcher_exception(to_string(ord.id) + " - AmendReject - " + E2);
                }
                ord.price = (ord.side == ASK ? 0.0 : INF);
            }
            if (check_details(old_ord, ord)) {
                price_diff = ord.price - old_ord.price;
                qty_diff = ord.qty - old_ord.pqty;
                if (price_diff == 0 && qty_diff == 0) {
                    throw matcher_exception(to_string(ord.id) + " - AmendReject - " + E2);
                }
                ord.pqty = ord.qty;
                ord.qty = max(old_ord.qty + qty_diff, 0LL);
                if (price_diff == 0 && qty_diff <= 0) {
                    ord.ts = old_ord.ts;
                }
                ob.mp.erase(it_mp);
                st.erase(old_ord);
                if (ord.qty > 0) {
                    ob.mp[ord.id] = ord;
                    st.insert(ord);
                }
                return to_string(ord.id) + " - AmendAccept\n";
            }
            throw matcher_exception(to_string(ord.id) + " - AmendReject - " + E2);
        }
        ob.mp.erase(it_mp);
        st.erase(old_ord);
    }
    else {
        for(auto &it_ob : sb) {
            if((it_ob.FF != ord.sec) && ((it_ob.SS).mp.find(ord.id) != (it_ob.SS).mp.end())) {
                throw matcher_exception(to_string(ord.id) + " - AmendReject - " + E2);
            }
        }
    }
    throw matcher_exception(to_string(ord.id) + " - AmendReject - " + E1);
}

string cancel_order(secbook &sb, vector < string > &cmd) {
    map < long, order > :: iterator it;
    map < string, ordbook > :: iterator it_ob;
    bool found = false;
    lli ordid = stoll(cmd[1]);
    for(it_ob = sb.begin(); it_ob != sb.end(); it_ob++) {
        it = (it_ob -> SS).mp.find(ordid);
        if (it != (it_ob -> SS).mp.end()) {
            found = true;
            break;
        }
    }
    if (found) {
        ordbook &ob = it_ob -> SS;
        order &ord = it -> SS;
        auto &st = ob.tradeside[ord.side];
        bool validity = isvalid(ord, ob.last_match_ts);
        st.erase(ord);
        ob.mp.erase(it);
        if (validity) {
            return to_string(ordid) + " - CancelAccept\n";
        }
    }
    throw matcher_exception(to_string(ordid) + " - CancelReject - " + E1);
}

string matchbook (ordbook &ob, lli curr_ts) {
    lli trade_qty;
    long double temp_price;
    order ord;
    stringstream matchlog;
    auto &ask = ob.tradeside[ASK];
    auto &bid = ob.tradeside[BID];
    auto it_ask = ask.begin();
    auto it_bid = bid.rbegin();
    while(it_ask != ask.end() && it_bid != bid.rend() && it_bid -> price >= it_ask -> price) {
        if (!isvalid(*it_ask, ob.last_match_ts)) {
            ob.mp.erase(it_ask -> id);
            ask.erase(it_ask);
            it_ask++;
            continue;
        }
        if (!isvalid(*it_bid, ob.last_match_ts)) {
            ob.mp.erase(it_bid -> id);
            bid.erase(next(it_bid).base());
            continue;
        }
        trade_qty = min(it_bid -> qty, it_ask -> qty);
        ord = *it_bid;
        ord.qty = trade_qty;
        temp_price = (it_ask -> type != MKT) ? it_ask -> price : it_bid -> price;
        ord.price = temp_price;
        matchlog << ord.sec << "|" << printorder(ord);
        ord = *it_bid;
        ord.qty -= trade_qty;
        ob.mp.erase(it_bid -> id);
        bid.erase(next(it_bid).base());
        if (ord.qty > 0) {
            bid.insert(ord);
            ob.mp[ord.id] = ord;
        }
        
        ord = *it_ask;
        ord.qty = trade_qty;
        ord.price = temp_price;
        matchlog << "|" << printorder(ord) << endl;
        ord = *it_ask;
        ord.qty -= trade_qty;
         
        ob.mp.erase(it_ask -> id);
        it_ask = ask.erase(it_ask);
        if (ord.qty > 0) {
            it_ask = ask.insert(ord).first;
            ob.mp[ord.id] = ord;
        }
       
    }
    ob.last_match_ts = curr_ts;
    return matchlog.str();
}

string match (secbook &sb, vector < string > &cmd) {
    string sec;
    stringstream matchlog;
    lli curr_ts = stoll(cmd[2]);
    if (cmd[1].size() > 0) {
        sec = cmd[1];
        validate(sec, 3);
        return matchbook(sb[sec], curr_ts);
    }
    for(auto &st : sb) {
        matchlog << matchbook(st.SS, curr_ts);
    }
    return matchlog.str();
}

string query (secbook &sb, vector < string > &cmd) {
    string sec;
    secbook temp_sb;
    
    if (cmd.size() == 1) {
        return printbook(sb);
    }
    else if (cmd.size() == 2) {
        try {
            validate(cmd[1], 7);        // timestamp given
            temp_sb = getbook(cmd[1]);
            return printbook(temp_sb);
        }
        catch (exception &e) {
            validate(cmd[1], 3);
            return printbook(sb[cmd[1]]);
        }
    }
    else if (cmd.size() == 3) {
        try {
            sec = cmd[1];
            validate(sec, 3);
            temp_sb = getbook(cmd[2], sec);
            return printbook(temp_sb[sec]);
        }
        catch (exception &e) {
            sec = cmd[2];
            validate(sec, 3);
            temp_sb = getbook(cmd[1], sec);
            return printbook(temp_sb[sec]);
        }
    }
    return E4;
}

string handle (secbook &sb, vector < string > &cmd) {
    if (cmd[0] == "N") {
        return add(sb, makeorder(cmd));
    }
    if (cmd[0] == "A") {
        return amend(sb, makeorder(cmd));
    }
    if (cmd[0] == "X") {
        return cancel_order(sb, cmd);
    }
    if (cmd[0] == "M") {
        return match(sb, cmd);
    }
    if (cmd[0] == "Q") {
        return query(sb, cmd);
    }
    return E4;
}

/*
 * Complete the function below.
 */
vector<string> processQueries(vector<string> queries) {
    // Write your code here.
    secbook sb;
    string inp, out;
    vector < string > cmd;
    string system_ts = "0";
    vector <string> responses;
    
    for(string inp : queries) {
        stringstream rs;
        if (inp.size() > 0) {
      	    cmd = parse(inp);
            if (cmd[0] != "Q") {
                if (cmd[0] == "M") {
                    adjust_timestamp(cmd, system_ts);
                }
                if (stoll(system_ts) > stoll(cmd[2])) {
                    if (cmd[0] == "M") {
                        rs << "Reject - " << E3;
                    }
                    else {
                        rs << cmd[1] << " - Reject - " << E3;
                    }
                    continue;
                }
                system_ts = cmd[2];
            }
            try {
                rs << handle(sb, cmd);
                if (cmd[0] != "Q") {
                    db.PB(cmd);
                }
            }
            catch (exception &e) {
                rs << e.what();
            }
            out = rs.str();
            if (out.length() > 0) {
                out.pop_back();
                responses.PB(out);
            }
	    }
    }
    return responses;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_size;
    cin >> queries_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_size);
    for (int queries_i = 0; queries_i < queries_size; queries_i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[queries_i] = queries_item;
    }

    vector<string> response = processQueries(queries);

    for (int response_itr = 0; response_itr < response.size(); response_itr++) {
        fout << response[response_itr];

        if (response_itr != response.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
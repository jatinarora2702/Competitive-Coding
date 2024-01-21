#include <iostream>

using namespace std;

enum Colors {
    Red, Green, Blue
};

enum class Vitamin {
    A, B, C, D, E, K, H
};

struct WindInfo {
    int speed, dir;
    
    void fn() {
        cout << "speed: " << speed << " | dir: " << dir << "\n"; 
    }
};

struct TempInfo {
    double deg, moisture;

    void fn() { 
        cout << "deg: " << deg << " | moisture: " << moisture << "\n";
    }
};

enum class WeatherType {
    Temp, Wind
};

// members cannot be a class (else default constructor needs to be explicitly defined)
// members cannot have same parent class (as per my vanilla experiments)
union Info {
    WindInfo wind_info;
    TempInfo temp_info;
};

class WeatherInfo {
public:
    WeatherType wtype;
    Info info;
    WeatherInfo(WeatherType _wtype, Info _info): wtype{_wtype} {
        if (wtype == WeatherType::Temp) {
            info.temp_info = _info.temp_info;
        }
        else {
            info.wind_info = _info.wind_info;
        }
    }
};

int main() {
    Colors c = Red;
    Vitamin vit = Vitamin::C;

    cout << c << "\n";
    
    if (vit == Vitamin::C) {
        cout << "Vit C\n";
    }
    else {
        cout << "Not Vit C\n";
    }

    Info info;
    info.temp_info = TempInfo{10.5, 0.1};
    WeatherInfo weather(WeatherType::Temp, info);

    cout << (weather.wtype == WeatherType::Temp ? "Temp" : "Wind") << "\n";
    if (weather.wtype == WeatherType::Temp)
        weather.info.temp_info.fn();
    else
        weather.info.wind_info.fn();
    return 0;
}
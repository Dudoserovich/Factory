#include <iostream>
#include <vector>

#define SO "Store order"

using namespace std;

enum COLOR {
    BLUE,
    BLACK,
    GRAY,
    WHITE,
    RAINBOW // секретный цвет для богатых
};

enum MATRIX {
    IPS,
    AMOLED,
    SUPER_AMOLED
};

string getColor(COLOR color) {
    switch (color) {
        case COLOR::BLUE:
            return "BLUE";
        case COLOR::BLACK:
            return "BLACK";
        case COLOR::GRAY:
            return "GRAY";
        case COLOR::WHITE:
            return "WHITE";
        default:
            return "RAINBOW"; // секретный цвет
    }
}

string getScreenMatrix(MATRIX color) {
    switch (color) {
        case MATRIX::IPS:
            return "IPS";
        case MATRIX::AMOLED:
            return "AMOLED";
        case MATRIX::SUPER_AMOLED:
            return "SUPER AMOLED";
    }
}

// фабрика телефонов
class Phone {
    string firm;
    string model;
    unsigned int power;   // заряд аккуммулятора
    COLOR color;          // раскраска задней крышки
    MATRIX screen_matrix; // матрица экрана
    string size_screen;    // размер дисплея
public:
    Phone(string firm, string model, COLOR color, unsigned int power, MATRIX screen_matrix, string size_screen) :
            firm(firm), model(model),
            color(color), power(power),
            screen_matrix(screen_matrix),
            size_screen(size_screen) {
    }

    const string &getFirm() const {
        return firm;
    }

    const string &getModel() const {
        return model;
    }

    COLOR getColor() const {
        return color;
    }

    MATRIX getMatrix() const {
        return screen_matrix;
    }

    string getDescription() {
        return firm + " " + model + " " + ::getColor(color) + ", " + to_string(power) +
        "mh " + size_screen + " " + ::getScreenMatrix(screen_matrix);
    }

    static Phone *createXiaomiPremium() {
        return new Phone("Xiaomi", "Mi 11", COLOR::GRAY, 4100,
                         MATRIX::IPS, "6.5");
    }

    static Phone *createIphoneFIVE() {
        return new Phone("Iphone", "5", COLOR::BLACK, 3000,
                         MATRIX::IPS, "5");
    }

    static Phone *createXiaomiDefault(COLOR color = COLOR::RAINBOW) {
        return new Phone("Xiaomi", "Mi 10", color, 3500, MATRIX::AMOLED, "6");
    }

};

int main() {
    vector<Phone *> phones1, phones2;

    phones1.push_back(Phone::createXiaomiPremium());

    for (int i = 0; i < 5; i++) {
        phones1.push_back(Phone::createXiaomiDefault(COLOR::BLUE));
    }

    cout << SO " 1: " << endl;
    for (int i = 0, len = phones1.size(); i < len; i++) {
        std::cout << phones1[i]->getDescription() << endl;
    }

    phones2.push_back(Phone::createIphoneFIVE());
    for (int i = 0; i < 4; i++) {
        phones2.push_back(Phone::createXiaomiPremium());
    }
    phones2.push_back(Phone::createXiaomiDefault());

    cout << SO << " 2: " << endl;
    for (int i = 0, len = phones2.size(); i < len; i++) {
        std::cout << phones2[i]->getDescription() << endl;
    }

    return 0;
}
#ifndef KIADONEMTALALHATO_H
#define KIADONEMTALALHATO_H

#endif // KIADONEMTALALHATO_H
#include <stdexcept>
#include <string>

    class KiadoNemTalalhato : public std::exception {
private:
    std::string message;

public:
    KiadoNemTalalhato(const std::string& kiadoNev)
        : message(kiadoNev + " kiadohoz nincs tarolt jatek" ) {}

    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

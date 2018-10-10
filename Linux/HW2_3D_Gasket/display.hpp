#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

class Display {
public:
    Display(int width, int height, const std::string& title);
    virtual ~Display();

    int width() const;
    int height() const;
    std::string title() const;
private:
    int width_;
    int height_;
    std::string title_;
};

#endif

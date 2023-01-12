#ifndef COLOR_H
#define COLOR_H

class Color
{
    public:
        float r, g, b; // Honestly, I don't see a reason to make it private.

        Color(float r, float g, float b);
	    // ~Color();

        float validateColorValue(float val);
        void setRed(float val);
        void setGreen(float val);
        void setBlue(float val);
};

#endif
#include <iostream>

using namespace std;
template <typename TemplateRectangle>
class Rectangle
{
private:
    TemplateRectangle length;
    TemplateRectangle width;
public:
    Rectangle(TemplateRectangle l, TemplateRectangle w) : length(l), width(w) {}

    TemplateRectangle getLength() const
    {
        return length;
    }

    void setLength(TemplateRectangle l)
    {
        length = l;
    }

    TemplateRectangle getWidth() const
    {
        return width;
    }

    void setWidth(TemplateRectangle w)
    {
        width = w;
    }
};

template <typename RectangleArea>
RectangleArea Area(const Rectangle<RectangleArea>& rectangle)
{
    return rectangle.getLength() * rectangle.getWidth();
}

int main()
{
    Rectangle<float> floatRectangle(3.5f, 2.5f);
    Rectangle<int> intRectangle(5, 4);

    cout << "Rectangle 1 (float): Length = " << floatRectangle.getLength() << ", Width = " << floatRectangle.getWidth() << endl;
    cout << "Rectangle 2 (int): Length = " << intRectangle.getLength() << ", Width = " << intRectangle.getWidth() << endl;

    cout << "\nArea of Rectangle 1: " << Area(floatRectangle) << endl;
    cout << "Area of Rectangle 2: " << Area(intRectangle) << endl;

    return 0;
}
#include "Shape.h"

// define window class
class Window 
{
public:
  // Upper left (x1, y1), lower right (x2, y2)
  Window(int x1, int y1, int x2, int y2) {
    ps = new Rectangle(x2-x1, y2-y1);
  }
  Window(int x1, int y1, int rad) {
    ps = new Circle(rad);
  }
  ~Window() {
    delete ps;
  }

  double GetDisplayArea() const {
    return ps->GetArea();
  }
  
  // other stuff: drawing, etc
  // skipped: no implementation for now

  // your code here

private:
  Shape *ps;
};




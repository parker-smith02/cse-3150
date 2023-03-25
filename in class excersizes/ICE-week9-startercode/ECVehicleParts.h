#ifndef _EC_VEHICLE_PARTS_H
#define _EC_VEHICLE_PARTS_H

// Engine type
enum EC_ENGINE_TYPE
{
  EC_ENGINE_4CYL = 0,
  EC_ENGINE_6CYL = 1,
  EC_ENGINE_ELECTRIC = 2
};

class ECPart 
{
  public:
    virtual ~ECPart() {}
    virtual int GetCost() const = 0;
};

// Engine
class ECEngine : public ECPart
{
public:
  ECEngine(EC_ENGINE_TYPE typeIn ) : type(typeIn) {}
  // what to put here?
  int GetCost() const {
    if (type == EC_ENGINE_4CYL) {
      return 1000;
    }
    if (type == EC_ENGINE_6CYL) {
      return 1500;
    }
    if (type == EC_ENGINE_ELECTRIC) {
      return 3000;
    }
  }
  private:
    EC_ENGINE_TYPE type;
};

// Wheel
class ECWheel : public ECPart
{
public:
  ECWheel(int sizeIn) : size(sizeIn) {}

  int GetCost() const {
    if (size == 17) {
      return 100;
    }
    if (size == 19) {
      return 150;
    }
  }
  private:
    int size;
};

// light
class ECLight 
{
public:
  int GetCost() const {
    return 50;
  }
};

#endif

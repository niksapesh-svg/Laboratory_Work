#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* data;
    int size;

    bool isValidValue(int value) const;

public:
    explicit DynamicArray(int size);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();

    int getSize() const;
    void print() const;

    void set(int index, int value);
    int get(int index) const;

    void addElement(int value);

    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif

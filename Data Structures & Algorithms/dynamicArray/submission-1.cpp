class DynamicArray {
private:
    int* arr;
    int len;
    int cap;

public:

    DynamicArray(int capacity) {
        this->cap = capacity;
        this->len = 0;
        this->arr = new int[capacity];
    }

    int get(int i) {
        return this->arr[i];
    }

    void set(int i, int n) {
        this->arr[i] = n;
    }

    void pushback(int n) {
        if (this->len == this->cap) {
            this->resize();
        }

        this->arr[this->len] = n;
        this->len++;
    }

    int popback() {
        this->len--;
        return this->arr[this->len];
    }

    void resize() {
        int* nArr = new int[this->cap * 2];
        for (int i = 0; i < this->len; i++) {
            nArr[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = nArr;

        this->cap = this->cap * 2;
    }

    int getSize() {
        return this->len;
    }

    int getCapacity() {
        return this->cap;
    }
};

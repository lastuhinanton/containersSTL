
namespace s21 {
    template <class value_type>
    vector<value_type>::vector() { this->NullVector(); }

    template <class value_type>
    vector<value_type>::vector(size_type n) { this->InitVector(); }

    template <class value_type>
    void vector<value_type>::NullVector() {
        size_ = 0;
        capacity_ = 0;
        container_ = nullptr;
    };

    template <class value_type>
    void vector<value_type>::InitVector() {
        size_ = n;
        capacity_ = n;
        container_ = new value_type[n];
    };

    template <class value_type>
    typename vector<value_type>::size_type vector<value_type>::size() const {
        return size_;
    }

}
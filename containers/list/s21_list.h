#ifndef S21_LIST_H
#define S21_LIST_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21
{
    template <typename T>
    class list
    {

    public:
        // List Member type

        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = std::size_t;

    private:
        struct Node
        {
            value_type data_;
            Node *next_;
            Node *prev_;

            Node(const value_type &value) : data_(value), next_(nullptr), prev_(nullptr) {}
        };

        //   Node* head_;
        //    Node* tail_;
        Node *end_;
        size_t size_;

    public:
        // List Functions
        list();
        list(size_type n);
        list(std::initializer_list<value_type> const &items);
        list(const list &l);
        list(list &&l);
        ~list();
        list &operator=(list &&l);

        // List Element access

        const_reference front() const;
        const_reference back() const;

        // List Capacity

        bool empty() const;
        size_type size();
        size_type max_size();

        // List Modifiers

        void clear();
        //   iterator insert(iterator pos, const_reference value);
        //   void erase(iterator pos);
        void push_back(const_reference value);
        void pop_back();
        void push_front(const_reference value);
        void pop_front();
        void swap(list &other);
        void merge(list &other);
        //   void splice(const_iterator pos, list& other);
        void reverse();
        void unique();
        void sort();

        template <typename value_type>
        class ListIterator
        {
        public:
            ListIterator()
            {
                ptr_ = nullptr;
            }

            ListIterator(Node *ptr) : ptr_(ptr){};

            reference operator*()
            {
                if (!this->ptr_)
                {
                    throw std::invalid_argument("Error! Value is nullptr.");
                }
                return this->ptr_->data_;
            }

            ListIterator operator++(int)
            {
                ptr_ = ptr_->next_;
                return *this;
            }

            ListIterator operator--(int)
            {
                ptr_ = ptr_->prev_;
                return *this;
            }

            ListIterator &operator++()
            {
                ptr_ = ptr_->next_;
                return *this;
            }

            ListIterator &operator--()
            {
                ptr_ = ptr_->prev_;
                return *this;
            }

            ListIterator operator+(const size_type value)
            {
                Node *tmp = ptr_;
                for (size_type i = 0; i < value; i++)
                {
                    tmp = tmp->next_;
                }
                ListIterator result(tmp);
                return result;
            }

            ListIterator operator-(const size_type value)
            {
                Node *tmp = ptr_;
                for (size_type i = 0; i < value; i++)
                {
                    tmp = tmp->prev_;
                }
                ListIterator result(tmp);
                return result;
            }

            bool operator==(ListIterator other)
            {
                return this->ptr_ == other.ptr_;
            }

            bool operator!=(ListIterator other)
            {
                return this->ptr_ != other.ptr_;
            }

        private:
            Node *ptr_ = nullptr;
            friend class list<T>;
        };

        template <typename value_type>
        class ListConstIterator : public ListIterator<T>
        {
        public:
            ListConstIterator(ListIterator<T> other) : ListIterator<T>(other) {}
            const T &operator*() { return ListIterator<T>::operator*(); }
        };

        //  List Member type
        using iterator = ListIterator<T>;
        using const_iterator = ListConstIterator<T>;

        // List Iterators

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;

        // List Modifiers
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);
        void splice(const_iterator pos, list &other);

    private:
        // Support functions
        //  void change_end();
        // void quick_sort(iterator left, iterator right);
        // iterator partition(iterator first, iterator last);
        //  void copy(const list& l);
        // void print_list();
    };
}
#endif // S21_LIST_H

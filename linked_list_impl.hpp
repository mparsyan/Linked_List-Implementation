template <typename T>
LinkedList<T>::LinkedList()
    : m_head(nullptr)
    , m_size(0)
    {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) 
    : m_head(nullptr)
    , m_size(0) 
    {
        Node* current = other.m_head;
        while (current != nullptr) {
            push_back(current->m_value);
            current = current->m_next;
        }
    }

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept 
    : m_head(other.m_head)
    , m_size(other.m_size)
    {
        other.m_head = nullptr;
        other.m_size = 0;
    }

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node* current = m_head;
    while (current != nullptr)
    {
        Node* tmp = current;
        current = current->m_next;
        delete tmp;
    }
    m_head = nullptr;
    m_size = 0;
}

template <typename T>
LinkedList<T>::Node::Node(const T& value)
    : m_value(value)
    , m_next(nullptr)
    {}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this != &other)
    {
        clear();
        Node* current = other.m_head;
        while (current != nullptr)
        {
            push_back(current->m_value);
            current = current->m_next;
        }
    }
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other) noexcept
{
    if (this != &other)
    {
        clear();
        Node* current = other.m_head;
        while (current != nullptr)
        {
            push_back(current->m_value);
            current = current->m_next;
        }
        other.clear();
    }
    return *this;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& other)
{
    if (this->size() != other.size())
    {
        return false;
    }
    auto node1 = this->m_head;
    auto node2 = other.m_head;

    while (node1 != nullptr && node2 != nullptr)
    {
        if (node1->m_value != node2->m_value)
        {
            return false;
        }
        node1 = node1->m_next;
        node2 = node2->m_next;
    }
    return true;
}

template <typename T>
bool LinkedList<T>::operator!=(const LinkedList<T>& other)
{
    return !(this == &other);
}

template <typename T>
bool LinkedList<T>::operator<(const LinkedList<T>& other)
{
    auto node1 = this->m_head;
    auto node2 = other.m_head;

    while (node1 != nullptr && node2 != nullptr) 
    {
        if (node1->m_value < node2->m_value) 
        {
            return true;
        }
        if (node1->m_value > node2->m_value) 
        {
            return false;
        }

        node1 = node1->m_next;
        node2 = node2->m_next;
    }

    return node1 == nullptr && node2 != nullptr;
}

template <typename T>
bool LinkedList<T>::operator<=(const LinkedList<T>& other)
{
    return !(this < other);
}

template <typename T>
bool LinkedList<T>::operator>(const LinkedList<T>& other)
{
    return this < &other;
}

template <typename T>
bool LinkedList<T>::operator>=(const LinkedList<T>& other)
{
    return !(this < &other);
}

template <typename T>
void LinkedList<T>::assign(size_t count, const T& value)
{
    clear();
    Node* tail = nullptr;
    for (size_t i = 0; i < count; ++i)
    {
       push_back(value);
    }
}

template <typename T>
T& LinkedList<T>::front()
{
    if (m_head == nullptr)
    {
        std::out_of_range("List is empty");
    }
    return m_head->m_value;
}

template <typename T>
T& LinkedList<T>::back()
{
    if (m_head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    Node* current = m_head;
    while (current->m_next != nullptr)
    {
        current = current->m_next;
    }
    return current->m_value;
}

template <typename T>
bool LinkedList<T>::empty() const
{
    return m_head == nullptr;
}

template <typename T>
size_t LinkedList<T>::size() const
{
    return m_size;
}

template <typename T>
size_t LinkedList<T>::max_size() const
{
    return 768614336404564650;
}

template <typename T>
void LinkedList<T>::clear()
{
    Node* current = m_head;
    while (current != nullptr)
    {
        Node* tmp = current;
        current = current->m_next;
        delete tmp;
    }
    m_head = nullptr;
    m_size = 0;
}

template <typename T>
void LinkedList<T>::insert(size_t index, const T& value)
{
    if (index > m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    Node* newNode = new Node(value);
    if (index == 0)
    {
        newNode->m_next = m_head;
        m_head = newNode;
    }
    else
    {
        Node* current = m_head;
        for (size_t i = 0; i < index - 1; ++i)
        {
            current = current->m_next;
        }
        newNode->m_next = current->m_next;
        current->m_next = newNode;
    }
    ++m_size;
}

template <typename T>
void LinkedList<T>::erase(size_t index)
{
    if (index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    Node* toDelete = m_head;
    if (index == 0)
    {
        m_head = m_head->m_next;
    }
    else
    {
        Node* current = m_head;
        for (size_t i = 0; i < index - 1; ++i)
        {
            current = current->m_next;
        }
        toDelete = current->m_next;
        current->m_next = toDelete->m_next;
    }
    delete toDelete;
    --m_size;
}

template <typename T>
void LinkedList<T>::push_back(const T& value)
{
    Node* newNode = new Node(value);
    if (m_head == nullptr)
    {
        m_head = newNode;
    }
    else
    {
        Node* current = m_head;
        while (current->m_next != nullptr)
        {
            current = current->m_next;
        }
        current->m_next = newNode;
    }
    ++m_size;
}

template <typename T>
void LinkedList<T>::push_front(const T& value)
{
    Node* newNode = new Node(value);
    newNode->m_next = m_head;
    m_head = newNode;
    ++m_size;
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if (m_head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    if (m_head->m_next == nullptr)
    {
        delete m_head;
        m_head = nullptr;
    }
    else
    {
        Node* current = m_head;
        while (current->m_next->m_next != nullptr)
        {
            current = current->m_next;
        }
        delete current->m_next;
        current->m_next = nullptr;
    }
    --m_size;
}

template <typename T>
void LinkedList<T>::pop_front()
{
    if (m_head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    Node* tmp = m_head;
    m_head = m_head->m_next;
    delete tmp;
    --m_size;
}

template <typename T>
void LinkedList<T>::resize(size_t new_size)
{

    while (new_size < m_size)
    {
        pop_back();
    }
    while (new_size > m_size)
    {
        push_back(0);
    }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& other)
{
    std::swap(m_head, other.m_head);
    std::swap(m_size, other.m_size);
}

template <typename T>
void LinkedList<T>::reverse()
{
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* current = m_head;
    while (current != nullptr)
    {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
}

template <typename T>
void LinkedList<T>::sort()
{
    for (Node* i = m_head; i != nullptr; i = i->m_next)
    {
        for (Node* j = i->m_next; j != nullptr; j = j->m_next)
        {
            if (i->m_value > j->m_value)
            {
                std::swap(i->m_value, j->m_value);
            }
        }
    }
}

template <typename T>
void LinkedList<T>::print_list()
{
    if (m_size == 0)
    {
        std::cout << "---";
    }
    Node* current = m_head;
    while(current)
    {
            std::cout << current->m_value << " ";
            current = current->m_next;

    }
    std::cout << std::endl;
}
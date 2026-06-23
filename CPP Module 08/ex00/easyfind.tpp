template <typename T>
typename T::iterator easyfind(T& container, int toFind)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), toFind);

    if ( it == container.end() )
    {
        throw NotFoundException();
    }

    return it;
}
template <typename T>
T min(T x, T y)
{
	if (x < y) return x;
	return y;
}

template <typename T>
T max(T x, T y)
{
	if (x > y) return x;
	return y;
}
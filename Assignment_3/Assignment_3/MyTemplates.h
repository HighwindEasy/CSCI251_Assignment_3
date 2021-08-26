#ifndef MYTEMPLATES_H_
#define MYTEMPLATES_H_

template <class T> double scalar_difference(T a, T b)
{
	double result = a.getScalarValue() - b.getScalarValue();
	return result;
}

template <class T> bool equals(T a, T b)
{
	return a == b;
}



#endif // !MYTEMPLATES_H_

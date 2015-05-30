# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	stack<T> valores;
	stack<T> minimos;
public:
	StackExt() {};
	bool empty() const; 
	T top() const;
	void pop();
	void push(const T & val);
	T findMin() const;
	T findMin2();
};

template <class T> 
bool StackExt<T>::empty() const
{
	return valores.empty();
}

template <class T> 
T StackExt<T>::top() const
{
	return valores.top();
}

template <class T> 
void StackExt<T>::pop()
{
	T val = valores.top();
	valores.pop();
	if ( minimos.top() == val ) minimos.pop();
}

template <class T> 
void StackExt<T>::push(const T & val)
{
	valores.push(val);
	if ( ! minimos.empty() ) {
		if ( val <= minimos.top() ) minimos.push(val); 
	}
	else minimos.push(val);
}

template <class T> 
T StackExt<T>::findMin() const
{
	return minimos.top();

}

// PARA APAGAR: Foi feito somente para verificar se
// o assert que verifica se executa em tempo constante
// funciona quando o método NAO executa em tempo constante
template <class T>
T StackExt<T>::findMin2()
{
	stack<T> temp = valores;

	T val_minimo;

	while (!temp.empty()) {
		if (temp.top() < val_minimo) {
			val_minimo = temp.top();
		}
		temp.pop();
	}

	return val_minimo;

}

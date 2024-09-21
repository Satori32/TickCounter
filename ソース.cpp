#include <iostream>
#include <cstdint>

template <class T>
struct TickCounter{
	T Count = 0;
	T One = 1;
	T OneTick = 1;
};

template<class T>
bool ConstructTickCounter(TickCounter<T>& In, const T& One, const T& OneTick) {
	In.Count = 0;
	In.One = One;
	In.OneTick = OneTick;
	return true;
}
template <class T>
T Up(TickCounter<T>& In) {
	In.Count += In.One;
	return In.Count;
}
template <class T>
T Now(TickCounter<T>& In) {
	return In.Count;
}
template <class T>
T Dowm(TickCounter<T>& In) {
	In.Count -= In.One;
	return In.Count;
}

template<class T>
T Tick(TickCounter<T>& In) {
	return In.Count / In.OneTick;
}

int main() {
	TickCounter<std::intmax_t> TC;

	ConstructTickCounter<std::intmax_t>(TC, 1, 3);

	Up(TC);
	Up(TC);
	Up(TC);

	Tick(TC);

	return 0;
}
Репозиторий для курса "Имитационное моделирование". Преподаватель: Духанов А. В.

В задании №2 было реализовано ДПСЧ с использованием метода Фибоначчи, протестировала его графическим способом с помощью гистограммы и статистическим тестом 

Интересный класс генераторов псевдослучайных последовательностей основан на использовании последовательностей Фибоначчи. Классический пример такой последовательности {0,1,1,2,3,5,8,13,21,34 …} - за исключением первых двух ее членов, каждый последующий член равен сумме двух предыдущих. Особенности распределения случайных чисел, генерируемых линейным конгруэнтным алгоритмом, делают невозможным их использование в статистических алгоритмах, требующих высокого разрешения.Наибольшую популярность фибоначчиевы датчики получили в связи с тем, что скорость выполнения арифметических операций с вещественными числами сравнялась со скоростью целочисленной арифметики, а фибоначчиевы датчики естественно реализуются в вещественной арифметике.
В методе Фибоначчи используют итеративную формулу
где X_{k} — вещественные числа из диапазона [0,1),a,b — целые положительные числа, называемые лагами. При реализации через целые числа достаточно формулы 
X_{k}=X_{{k-a}}-X_{{k-b}} (при этом будут происходить арифметические переполнения). Для работы фибоначчиеву генератору требуется знать
max{a,b} предыдущих сгенерированных случайных чисел. При программной реализации для хранения сгенерированных случайных чисел используется конечная циклическая очередь на базе массива. Для старта фибоначчиевому генератору требуется 
Получаемые случайные числа обладают хорошими статистическими свойствами, причём все биты случайного числа равнозначны по статистическим свойствам. Период фибоначчиева генератора может быть оценён по следующей формуле:

T=(2^{{\max\{a,b\}}}-1)\cdot 2^{{\ell }},где ℓ\ell — число битов в мантиссе вещественного числа.

Графический метод тестирования датчика псевдослучайных чисел позволяет оценить равномерность распределения символов в последовательности и определить частоту повторения каждого символа. Этот метод позволяет оценить, насколько хорошо распределение чисел соответствует равномерному распределению. В программе выводится гистограмма, в которой для каждого интервала отображается диапазон значений и количество чисел, попавших в этот диапазон. Они должны быть примерно одинаково распределены. Однако следует отметить, что этот метод не обнаруживает всех видов неравномерностей и корреляций в последовательности случайных чисел, поэтому следует дополнять другими методами тестирования, такими как статистические тесты χ².

Чтобы понять, что генератор псевдослучайных чисел возвращает числа, распределенные равномерно, мы можем использовать тест χ². Этот тест позволяет оценить, насколько хорошо распределены сгенерированные числа по заданным интервалам или отрезкам.Числа, генерируемые генератором Вихря-Мерсенна, делятся на заданное количество интервалов. Затем считается, сколько чисел попало в каждый из этих интервалов. Если генератор чисел равномерный, то ожидается, что каждый интервал будет содержать примерно одинаковое количество чисел. Однако, если числа не равномерно распределены, то одни интервалы будут содержать больше чисел, чем ожидается, а другие меньше. Тест хи-квадрат вычисляет статистику хи-квадрат, которая измеряет отклонение фактического распределения от ожидаемого равномерного распределения. Если статистика хи-квадрат меньше критического значения для заданного уровня значимости, это может указывать на то, что сгенерированные числа действительно равномерно распределены. В противном случае, если статистика хи-квадрат слишком велика, это может указывать на неравномерность распределения и плохую случайность генератора. Таким образом, чем меньше статистика хи-квадрат и ближе она к ожидаемому значению, тем больше вероятность того, что генератор возвращает числа, распределенные более равномерно. Этот тест позволяет оценить качество случайных чисел, генерируемых генератором, и проверить, соответствует ли его выход равномерному распределению.

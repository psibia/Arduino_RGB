Как пользоваться библиотекой Sibia

Библиотека предназначена для целевой платформы .NET 4.7.2

Имеет 3 общедоступных byte свойства:

SibiaLights.Red
SibiaLights.Green
SibiaLights.Blue

Имеет 2 общедоступных статических метода:

SibiaLights.GetColors();
Данный метод присваивает трем статическим свойствам (Red, Green, Blue) значение цвета
пикселя, который находится под курсором мыши на элементе фреймворка
Фактически данный метод имеет следующую конфигурацию, которая опускается при вызове:

public static void GetColors<T>(T element, MouseButtonEventArgs e)
where T : FramevorkElement
{}

SibiaLights.ColorsToArduino();
Данный метод преобразует значение трех свойств в строку из 9 символов (первые 3 символа
соответствуют свойству Red, второе и третье - Green и Blue, соответственно) и возвращает
данную строку


Библиотеку разрешено применять в образовательных целях. Коммерческое использование запрещено
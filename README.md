Инструкции:

1. Програмата се стартира от файлa minesweeper.cpp, който се намира в оснвната директория на проекта. В него се съдържа main() функцията.

2. При стартиране на играта, в конзолата се генерира дъската. В крайните редове и колони са отбелязани цифрите от 1 до 9. 
    Те служат като навигация за координатитие на дадена клетка. Всички останали клетки са празни.

3. В конзолата се въвеждат коордиантите на избраната от нас клетка и действието, което искаме да извършим в нея. 
    Първо се въвежда реда на клетката, след това колоната и накрая действието. Трите неща трябва да се намират на интервал разстояние
    едно от друго или всяко да е на отделен ред. За да разкрием клетка въвеждаме "s", а за да я маркираме въвеждаме "m". Ако въведем
    невалидни координати или невалидна команда, ще получим подкана да въведем валидни данни.

4. Когато се разкрие дадена позиция, ако на нея има мина, се изписва "Х", разкриват се всички останали позиции, на които има мина, и играта приключва.
    Ако на тази позиция няма мина, в нея се изписва число, показващо колко мини има в заобикалящите я 8 позиции. Ако се опитаме да разкрием или
    маркираме позиция, която вече е разкрита, получаваме подкана да изберем някоя друга клетка.

5. Когато се маркира дадена позиция, на нея се появява знака "!". Ако отново въведем командата за маркиране върху същата клетка, то отбелязването
    ще се премахне, а ако въведем командата за разкриване, то ще получим подкана първо да премахнем отбелязването и след това да разкрием тази позиция.
    Играта приключва, когато играчът правилно е отбелязал всички мини, но е отбелязал единствено тях, т.е. няма други отбелязани позиции. Не е задължително всички останали позиции да са разкрити. 
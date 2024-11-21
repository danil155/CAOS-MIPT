.global f
f:
    // x3 - это x
    // x0 - это A
    // x1 - это B
    // x2 - это C

    // Вычисляем x^2 (x * x)
    mul x4, x3, x3           // x4 = x^2

    // Вычисляем Ax^2 (A * x^2)
    mul x5, x0, x4           // x5 = A * x^2

    // Вычисляем Bx (B * x)
    mul x6, x1, x3           // x6 = B * x

    // Теперь складываем Ax^2, Bx и C
    add x0, x5, x6           // x0 = Ax^2 + Bx
    add x0, x0, x2           // x0 = Ax^2 + Bx + C

    // Результат уже в x0
    ret                       // Возвращаем управление


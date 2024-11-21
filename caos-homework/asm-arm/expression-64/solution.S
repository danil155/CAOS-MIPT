.global f
f:
    mul x4, x3, x3           // x4 = x^2

    mul x5, x0, x4           // x5 = A * x^2

    mul x6, x1, x3           // x6 = B * x

    add x0, x5, x6           // x0 = Ax^2 + Bx
    add x0, x0, x2           // x0 = Ax^2 + Bx + C

    ret

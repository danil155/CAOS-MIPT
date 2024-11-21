.global sum
sum:
    mov w3, w0
    mov x4, #0

loop:
    cmp x4, x1
    bge end

    ldr w5, [x2, x4, LSL #2]
    add w3, w3, w5

    add x4, x4, #1
    b loop

end:
    mov w0, w3
    ret

import turtle


def fract_draw_by_depth(stp, rule, ang, dept):
    if dept < 1:
        return
    if rule == "a":
        turtle.left(ang)
        fract_draw_by_depth(stp, "b", ang, dept - 1)
        turtle.forward(stp)
        turtle.right(ang)
        fract_draw_by_depth(stp, "a", ang, dept - 1)
        turtle.forward(stp)
        fract_draw_by_depth(stp, "a", ang, dept - 1)
        turtle.right(ang)
        turtle.forward(stp)
        fract_draw_by_depth(stp, "b", ang, dept - 1)
        turtle.left(ang)
    if rule == "b":
        turtle.right(ang)
        fract_draw_by_depth(stp, "a", ang, dept - 1)
        turtle.forward(stp)
        turtle.left(ang)
        fract_draw_by_depth(stp, "b", ang, dept - 1)
        turtle.forward(stp)
        fract_draw_by_depth(stp, "b", ang, dept - 1)
        turtle.left(ang)
        turtle.forward(stp)
        fract_draw_by_depth(stp, "a", ang, dept - 1)
        turtle.right(ang)


def fract_draw_by_step(stp, rule, ang):
    if stp < 40:
        return
    stp /= 1.1
    if rule == "a":
        turtle.left(ang)
        fract_draw_by_step(stp, "b", ang)
        turtle.forward(stp)
        turtle.right(ang)
        fract_draw_by_step(stp, "a", ang)
        turtle.forward(stp)
        fract_draw_by_step(stp, "a", ang)
        turtle.right(ang)
        turtle.forward(stp)
        fract_draw_by_step(stp, "b", ang)
        turtle.left(ang)
    if rule == "b":
        turtle.right(ang)
        fract_draw_by_step(stp, "a", ang)
        turtle.forward(stp)
        turtle.left(ang)
        fract_draw_by_step(stp, "b", ang)
        turtle.forward(stp)
        fract_draw_by_step(stp, "b", ang)
        turtle.left(ang)
        turtle.forward(stp)
        fract_draw_by_step(stp, "a", ang)
        turtle.right(ang)

turtle.speed(10)
turtle.penup()
turtle.goto(-300, -200)
turtle.pendown()
length = 400
generations = 4
# draw_koch_curve(length, generations)


# fract_draw_by_depth(30, "a", 90, 4)
# turtle.penup()
# turtle.goto(-200, -300)
# turtle.pendown()
fract_draw_by_step(40 *1.1 * 1.1 * 1.1, "a", 90)
# fract_draw_by_step(40 * 1.1 * 1.1 * 1.2, "a", 90)
turtle.done()
print("done")
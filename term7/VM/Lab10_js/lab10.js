function setup()
{
    let width = windowWidth;
    let height = windowHeight;
    createCanvas(width, height);
    background(230);

    a = 0;
    b = 2;
    h1 = 0.1;
    h2 = 0.01;
    u0 = 2;

    xValues_h1 = get_x(a, b, h1)
    xValues_h2 = get_x(a, b, h2)
    exact_values = get_exactValues(xValues_h1, y);
    explicit_values_h1 = explicit_scheme(xValues_h1, y, u0, h1);    
    explicit_values_h2 = explicit_scheme(xValues_h2, y, u0, h2);    
    implicit_values_h1 = implicit_scheme(xValues_h1, y, u0, h1);
    implicit_values_h2 = implicit_scheme(xValues_h2, y, u0, h2);

    console.log(xValues_h1, exact_values)
    maxY = max(
        max(exact_values),
        max(explicit_values_h1),
        max(explicit_values_h2),
        max(implicit_values_h1),
        max(implicit_values_h2));

    drawGrid(width, height, maxY, xValues_h1);
    drawGraph(width, height, maxY, xValues_h1.map((x, i) => ({x, y: exactValues[i]})), stroke(222, 95, 95))
    drawGraph(width, height, maxY, xValues_h1.map((x, i) => ({x, y: explicit_values_h1[i]})), stroke(116, 158, 84))
    drawGraph(width, height, maxY, xValues_h2.map((x, i) => ({x, y: explicit_values_h2[i]})), stroke(58, 115, 14))
    drawGraph(width, height, maxY, xValues_h1.map((x, i) => ({x, y: implicit_values_h1[i]})), stroke(73, 171, 184))
    drawGraph(width, height, maxY, xValues_h2.map((x, i) => ({x, y: implicit_values_h2[i]})), stroke(19, 106, 117))

    stroke(222, 95, 95)
    line(100, 50, 200, 50)
    noStroke()
    text("exaxt", 210, 55)

    stroke(116, 158, 84)
    line(300, 50, 400, 50)
    noStroke()
    text("explicit_h1", 410, 55)

    stroke(58, 115, 14)
    line(500, 50, 600, 50)
    noStroke()
    text("explicit_h2", 610, 55)

    stroke(73, 171, 184)
    line(700, 50, 800, 50)
    noStroke()
    text("implicit_h1", 810, 55)

    stroke(19, 106, 117)
    line(900, 50, 1000, 50)
    noStroke()
    text("implicit_h2", 1010, 55)

}
function y(x)
{
    return (56 / 27) * Math.exp(3 * x) - (1 / 3) * x * x - (2 / 9) * x - (2 / 27);
}

function u(y, x)
{
    return x * x + 3 * y(x);
}


function drawGraph(w, h, max_value, points, stroke) {
    let top_margin = h * 0.1;
    let bottom_margin = h * 0.1;
    let left_margin = w * 0.05;
    let right_margin = w * 0.02;

    strokeWeight(3)

    let y_max = Math.ceil(max_value / 10) * 10;
    old_x = map(points[0].x, points[0].x, points[points.length - 1].x, left_margin, width - right_margin);
    old_y = map(points[0].y, 0, y_max, height - bottom_margin, top_margin);

    for (let i = 1; i < points.length; i++) {
        let x = map(points[i].x, points[0].x, points[points.length - 1].x, left_margin, width - right_margin);
        let y = map(points[i].y, 0, y_max, height - bottom_margin, top_margin);
        line(old_x, old_y, x, y);
        old_x = x;
        old_y = y;
    }
}

function drawGrid(w, h, max_value, xValues) {
    let top_margin = h * 0.1;
    let bottom_margin = h * 0.1;
    let left_margin = w * 0.05;
    let right_margin = w * 0.02;

    // draw margin lines    
    {
        // stroke(255);
        // let dashLength = 10;
        // let dashGap = 5;
        // strokeCap(ROUND);
        // strokeJoin(ROUND);
        // drawingContext.setLineDash([dashLength, dashGap]);
        // line(0, top_margin, width, top_margin);
        // line(0, top_margin / 2 , width, top_margin / 2);
        // line(0, height - bottom_margin, width, height - bottom_margin);
        // line(left_margin, 0, left_margin, height);
        // line(width - right_margin, 0, width - right_margin, height);
        // line(width / 2, 0, width / 2, height);
        // drawingContext.setLineDash([0]);
    }
    
    for (let i = xValues[0]; i < xValues[xValues.length - 1] + 0.01; i+= 0.1) {
        let x = map(i, xValues[0], xValues[xValues.length - 1], left_margin, width - right_margin);
        strokeWeight(2)
        line(x, height - bottom_margin - 5, x, height - bottom_margin + 5);     
        strokeWeight(1)
        line(x, height - bottom_margin, x, top_margin);   
        text(i.toFixed(1), x - 8, height - bottom_margin + 20);
    }

    let y_max = Math.ceil(max_value / 10) * 10;

    for(let i = 0; i <= y_max; i += y_max/10) {
        let y = map(i, 0, y_max, height - bottom_margin, top_margin);
        strokeWeight(2)
        line(left_margin - 5, y, left_margin + 5, y);
        strokeWeight(1)
        line(left_margin, y, width - right_margin, y);
        text(i, left_margin - 30, y + 4);
    }

    // draw axis
    strokeWeight(2)
    line(left_margin, height - bottom_margin, width - right_margin, height - bottom_margin);
    line(left_margin, height - bottom_margin, left_margin, top_margin);

}

function get_exactValues(xValues, g){
    exactValues = [];
    xValues.forEach(element => {
        exactValues.push(g(element));
    });
    return exactValues;
}

function get_x(a, b, h){
    let x = [];
    for(let i = a; i <= b; i = +(i + h).toFixed(2)){
        x.push(i);
    }
    return x;
}

function explicit_scheme(x, y, u0, h)
{
    let yValues = Array(x.length);
    yValues[0] = u0;
    for(let i = 1; i < x.length; i++)
    {
        yValues[i] = yValues[i-1] + h* u(y, x[i-1]);
    }
    return yValues;
}

function implicit_scheme(x, y, u0, h)
{
    let yValues = Array(x.length);
    yValues[0] = u0;
    for(let i = 1; i < x.length; i++)
    {
        yValues[i] = y(x[i]) + 1/2 * h * u(y, x[i-1]);
    }

    return yValues;
}
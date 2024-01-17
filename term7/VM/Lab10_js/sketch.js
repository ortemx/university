function setup() {
    let width = windowWidth;
    let height = windowHeight;
    createCanvas(width, height);
    background(230);


    let h1 = 0.1;
    let h2 = 0.01;
    let x0 = [0, 0, 0]
    let x1 = [2, 1, 1]
    let u0 = [2, 1, 0]
    let result1 = solveEulerSymmetric(f3, x0[2], u0[2], h1, (x1[2] - x0[2]) / h1);
    let result2 = solveEulerSymmetric(f3, x0[2], u0[2], h2, (x1[2] - x0[2]) / h2);

    let xValues1 = get_x(x0[2], x1[2], h1);
    let xValues2 = get_x(x0[2], x1[2], h2);
    let exactValues = get_exactValues(xValues2, g3);


    max_value = max(
        max(result1),
        max(result2),
        max(exactValues)
    );

    drawGrid(width, height, max_value, xValues1);
    // график при h = 0.1 (темно зеленый)
    drawGraph(width, height, max_value, xValues1.map((x, i) => ({x, y: result1[i]})), stroke(35, 130, 124))
    // график при h = 0.01 (синий)
    drawGraph(width, height, max_value, xValues2.map((x, i) => ({x, y: result2[i]})), stroke(54, 115, 229))
    // точные значения (красный)
    drawGraph(width, height, max_value, xValues2.map((x, i) => ({x, y: exactValues[i]})), stroke(229, 115, 115))
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

    // stroke(255);
    // fill(255);
    
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

function f1(x, u) {
    return x * x + 3 * u;
}

function g1(x) {
    return (56 / 27) * Math.exp(3 * x) - (1 / 3) * x * x - (2 / 9) * x - (2 / 27);
}

function f2(x, u) {
    return 2 * u + 4 * x;
}

function g2(x) {
    return -2 * x + 2 * Math.exp(2 * x) - 1;
}

function f3(x, u) {
    return 2 * u + Math.exp(x);
}

function g3(x) {
    return Math.exp(x) * (Math.exp(x) - 1);
}
function solveEulerSymmetric(f, x0, u0, h, n) {
    let result = [u0];

    let x = x0;
    let u = u0;

    for (let i = 0; i < n; i++) {
        let xHalf = x + h / 2;
        let uHalf = u + (h / 2) * f(x, u);

        x += h;
        u += h * f(xHalf, uHalf);

        result.push(u);
    }

    return result;
}

function get_x(a, b, h){
    let x = [];
    for(let i = a; i <= b; i = +(i + h).toFixed(2)){
        x.push(i);
    }
    return x;
}

function get_exactValues(xValues, g){
    exactValues = [];
    xValues.forEach(element => {
        exactValues.push(g(element));
    });
    return exactValues;
}

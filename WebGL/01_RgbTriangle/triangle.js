var vertexShaderSrc = [
    'precision mediump float;',
    'attribute vec2 vertPosition;',
    'attribute vec3 vertColor;',
    'varying vec3 fragColor;',
    '',
    'void main() {',
    '   gl_Position = vec4(vertPosition, 0.0, 1.0);',
    '   fragColor = vertColor;',
    '}'
].join('\n');

var fragmentShaderSrc = [
    'precision mediump float;',
    'varying vec3 fragColor;',
    '',
    'void main() {',
    '   gl_FragColor = vec4(fragColor, 1.0);',
    '}'
].join('\n')


// Define triangle verticies and colors and allocate memory on
// the GPU that we're ready to use.
var triangleVertices = [
    0.0, 0.5,
    -0.5, -0.5,
    0.5, -0.5
];

var triangleColors = [
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0
];


var positionAttribLocation;
var colorAttribLocation;
var verticesBuffer;
var colorsBuffer;

function init() {
    canvas = document.getElementById('main_canvas');
    gl = canvas.getContext('webgl') || canvas.getContext('experimental-webgl');

    if (!gl) {
        alert("Your browser does not support WebGL");
        return;
    }

    gl.enable(gl.DEPTH_TEST); 

    var program = createProgram(gl, vertexShaderSrc, fragmentShaderSrc);
    gl.useProgram(program);

    positionAttribLocation = gl.getAttribLocation(program, 'vertPosition');
    colorAttribLocation = gl.getAttribLocation(program, 'vertColor');

    verticesBuffer = gl.createBuffer();
    colorsBuffer = gl.createBuffer();
}

function createProgram(gl, vertexShaderSource, fragmentShaderSource) {
    // Compile vertex shader from source.
    var vertexShader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vertexShader, vertexShaderSource);
    gl.compileShader(vertexShader);
    if (!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS)) {
        throw "[ERROR] error compiling vertex shader: " + gl.getShaderInfoLog(vertexShader);
    }

    // Compile fragment shader from source.
    var fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fragmentShader, fragmentShaderSource);
    gl.compileShader(fragmentShader);
    if (!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)) {
        throw "[ERROR] error compiling fragment shader: " + gl.getShaderInfoLog(fragmentShader);
    }

    // Create WebGLProgram object and attach the two shaders to it.
    var program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);
    if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
        throw "[ERROR] link error in program: " + gl.getProgramInfoLog(program);
    }

    return program;
}

function draw() {
    gl.clearColor(0.2, 0.2, 0.2, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    gl.bindBuffer(gl.ARRAY_BUFFER, verticesBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(triangleVertices), gl.STATIC_DRAW);
    gl.vertexAttribPointer(positionAttribLocation, 2, gl.FLOAT, gl.FALSE, 2 * Float32Array.BYTES_PER_ELEMENT, 0);
    gl.enableVertexAttribArray(positionAttribLocation);

    gl.bindBuffer(gl.ARRAY_BUFFER, colorsBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(triangleColors), gl.STATIC_DRAW);
    gl.vertexAttribPointer(colorAttribLocation, 3, gl.FLOAT, gl.FALSE, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
    gl.enableVertexAttribArray(colorAttribLocation);
 
    // Main render loop
    gl.drawArrays(gl.TRIANGLES, 0, 3);
}


function main() {
    init();
    draw();
}

var vertexShaderSrc = [
    'precision mediump float;',
    'attribute vec3 vertPosition;',
    'attribute vec3 vertColor;',
    'varying vec3 fragColor;',
    'uniform mat4 mWorld;',
    'uniform mat4 mView;',
    'uniform mat4 mProj;',
    '',
    'void main() {',
    '   gl_Position = mProj * mView * mWorld * vec4(vertPosition, 1.0);',
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
var colorcubeVertices = [
    -1.0, -1.0, -1.0, // 0
    1.0, -1.0, -1.0,  // 1
    1.0, 1.0, -1.0,   // 2
    -1.0, 1.0, -1.0,  // 3
    -1.0, -1.0, 1.0,  // 4
    1.0, -1.0, 1.0,   // 5
    1.0, 1.0, 1.0,    // 6
    -1.0, 1.0, 1.0    // 7
];

var colorcubeColors = [
    0.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    1.0, 1.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 0.0, 1.0,
    1.0, 1.0, 1.0,
    0.0, 1.0, 1.0
];

var colorcubeIndices = [
    7, 3, 2,  // top 1
    7, 6, 2,  // top 2
    7, 3, 0,  // left 1
    7, 4, 0,  // left 2
    6, 2, 1,  // right 1
    6, 5, 1,  // right 2
    7, 4, 5,  // front 1
    7, 6, 5,  // front 2
    3, 1, 2,  // back 1
    3, 1, 0,  // back 2
    0, 4, 5,  // bottom 1
    0, 1, 5   // bottom 2
];

var positionAttribLocation;
var colorAttribLocation;

var matWorldUniformLocation;
var matViewUniformLocation;
var matProjUniformLocation;

var identityMatrix;
var worldMatrix; 
var viewMatrix;
var projMatrix;

var verticesBuffer;
var colorsBuffer;
var indicesBuffer;

var theta_x;
var theta_y;
var theta_z;

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

    matWorldUniformLocation = gl.getUniformLocation(program, 'mWorld');
    matViewUniformLocation = gl.getUniformLocation(program, 'mView');
    matProjUniformLocation = gl.getUniformLocation(program, 'mProj');
    identityMatrix = new Float32Array(16);

    mat4.identity(identityMatrix);
    worldMatrix = new Float32Array(16);
    viewMatrix = new Float32Array(16);
    projMatrix = new Float32Array(16);

    verticesBuffer = gl.createBuffer();
    colorsBuffer = gl.createBuffer();
    indicesBuffer = gl.createBuffer();

    theta_x = 0;
    theta_y = 0;
    theta_z = 0;


    // Vertices
    gl.bindBuffer(gl.ARRAY_BUFFER, verticesBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(colorcubeVertices), gl.STATIC_DRAW);
    gl.vertexAttribPointer(positionAttribLocation, 3, gl.FLOAT, gl.FALSE, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
    gl.enableVertexAttribArray(positionAttribLocation);

    // Indices
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indicesBuffer);
    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(colorcubeIndices), gl.STATIC_DRAW);

    // Colors
    gl.bindBuffer(gl.ARRAY_BUFFER, colorsBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(colorcubeColors), gl.STATIC_DRAW);
    gl.vertexAttribPointer(colorAttribLocation, 3, gl.FLOAT, gl.FALSE, 3 * Float32Array.BYTES_PER_ELEMENT, 0);
    gl.enableVertexAttribArray(colorAttribLocation);

}

function keyEventHandler(e) {
    if (e.keyCode == '38') {
        // up arrow key
        theta_x += 3;
    } else if (e.keyCode == '40') {
        // down arrow key
        theta_x -= 3;
    } else if (e.keyCode == '37') {
        // left arrow key
        theta_z -= 3;
    } else if (e.keyCode == '39') {
        // right arrow key
        theta_z += 3;
    }
}

function draw() {
    gl.clearColor(0.2, 0.2, 0.2, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    mat4.lookAt(viewMatrix, [0, -5, -5], [0, 0, 0], [0, 1, 0]);
    gl.uniformMatrix4fv(matViewUniformLocation, gl.FALSE, viewMatrix);

    mat4.perspective(projMatrix, glMatrix.toRadian(45), canvas.width / canvas.height, 0.1, 1000.0);
    gl.uniformMatrix4fv(matProjUniformLocation, gl.FALSE, projMatrix);

    mat4.identity(worldMatrix);
    mat4.rotate(worldMatrix, worldMatrix, glMatrix.toRadian(theta_x), [1, 0, 0]);
    mat4.rotate(worldMatrix, worldMatrix, glMatrix.toRadian(theta_y), [0, 1, 0]);
    mat4.rotate(worldMatrix, worldMatrix, glMatrix.toRadian(theta_z), [0, 0, 1]);
    gl.uniformMatrix4fv(matWorldUniformLocation, gl.FALSE, worldMatrix);

    gl.drawElements(gl.TRIANGLES, colorcubeIndices.length, gl.UNSIGNED_SHORT, 0);
    requestAnimationFrame(draw);
}


function main() {
    init();
    document.onkeydown = keyEventHandler;

    // Main render loop.
    requestAnimationFrame(draw);
}

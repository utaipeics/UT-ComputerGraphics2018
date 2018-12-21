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

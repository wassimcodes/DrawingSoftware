#version 330 core

out vec4 FragColor;
uniform vec4 u_BrushColor; // Uniform for brush color

void main() {
    FragColor = u_BrushColor;
}

#version 120

uniform sampler2D diffuse;

varying vec2 texCoord_out;

void main(){
	gl_FragColor = texture2D(diffuse, texCoord_out);
}
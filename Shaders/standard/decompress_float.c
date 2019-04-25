A = abs(TO_DECOMPRESS.xyz);
s = sign(TO_DECOMPRESS.xyz);
s += vec3(1.0) - abs(s);
B = floor(A/COMPRESSED_POSITION);
A = A - B*COMPRESSED_POSITION;

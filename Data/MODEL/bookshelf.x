xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 206;
 450.36466;76.16864;-189.56848;,
 506.38448;76.16864;-189.56848;,
 506.38448;44.22176;-189.56848;,
 413.87027;44.22176;-189.56848;,
 450.36466;76.16864;189.56848;,
 413.87027;44.22176;189.56848;,
 506.38448;44.22176;189.56848;,
 506.38448;76.16864;189.56848;,
 -447.47759;76.16864;-189.56848;,
 -410.98321;44.22176;-189.56848;,
 -506.38448;44.22176;-189.56848;,
 -506.38448;76.16864;-189.56848;,
 -447.47759;76.16864;189.56848;,
 -506.38448;76.16864;189.56848;,
 -506.38448;44.22176;189.56848;,
 -410.98321;44.22176;189.56848;,
 506.38448;76.16864;-148.67808;,
 506.38448;44.22176;-148.67808;,
 506.38448;44.22176;-189.56848;,
 506.38448;76.16864;-189.56848;,
 506.38448;76.16864;-148.67808;,
 506.38448;76.16864;-189.56848;,
 450.36466;76.16864;-189.56848;,
 450.36466;76.16864;-187.92625;,
 -447.47759;76.16864;-189.56848;,
 -447.47759;76.16864;-187.92625;,
 413.87027;44.22176;-126.11488;,
 -410.98321;44.22176;-126.11488;,
 -410.98321;44.22176;-189.56848;,
 413.87027;44.22176;-189.56848;,
 -506.38448;76.16864;-189.56848;,
 -506.38448;76.16864;-148.67808;,
 -506.38448;76.16864;-148.67808;,
 -506.38448;76.16864;-189.56848;,
 -506.38448;44.22176;-189.56848;,
 -506.38448;44.22176;-148.67808;,
 506.38448;76.16864;148.67808;,
 506.38448;76.16864;189.56848;,
 506.38448;44.22176;189.56848;,
 506.38448;44.22176;148.67808;,
 506.38448;76.16864;148.67808;,
 450.36466;76.16864;148.67808;,
 506.38448;44.22176;148.67808;,
 413.87027;44.22176;126.11488;,
 506.38448;44.22176;-148.67808;,
 -447.47759;76.16864;148.67808;,
 413.87027;44.22176;189.56848;,
 -410.98321;44.22176;189.56848;,
 -410.98321;44.22176;126.11488;,
 -506.38448;76.16864;148.67808;,
 -506.38448;44.22176;148.67808;,
 -506.38448;44.22176;-148.67808;,
 -506.38448;76.16864;148.67808;,
 -506.38448;44.22176;148.67808;,
 -506.38448;44.22176;189.56848;,
 -506.38448;76.16864;189.56848;,
 506.38448;-1.96944;-148.67808;,
 461.70035;-1.96944;-148.67808;,
 461.70035;-1.96944;-189.56848;,
 506.38448;-1.96944;-189.56848;,
 -458.81329;-1.96944;-149.42144;,
 -506.38448;-1.96944;-148.67808;,
 -506.38448;-1.96944;-189.56848;,
 -458.81329;-1.96944;-190.51632;,
 506.38448;-1.96944;148.67808;,
 506.38448;-1.96944;189.56848;,
 461.70035;-1.96944;189.56848;,
 461.70035;-1.96944;148.67808;,
 -458.81329;-1.96944;149.42144;,
 -458.81329;-1.96944;190.51632;,
 -506.38448;-1.96944;189.56848;,
 -506.38448;-1.96944;148.67808;,
 492.59840;21.61856;-148.67808;,
 424.32974;21.61856;-148.67808;,
 424.32974;21.61856;-189.56848;,
 506.38448;44.22176;-189.56848;,
 506.38448;21.61856;-189.56848;,
 -419.24161;21.61856;-148.67808;,
 -506.38448;21.61856;-148.67808;,
 -506.38448;44.22176;-189.56848;,
 -506.38448;21.61856;-189.56848;,
 -419.24161;21.61856;-189.56848;,
 506.38448;21.61856;148.67808;,
 506.38448;21.61856;189.56848;,
 424.32974;21.61856;189.56848;,
 424.32974;21.61856;148.67808;,
 -419.24161;21.61856;148.67808;,
 -419.24161;21.61856;189.56848;,
 -506.38448;21.61856;189.56848;,
 -506.38448;21.61856;148.67808;,
 506.38448;1250.04006;148.67808;,
 450.36466;1250.04006;148.67808;,
 450.36466;1250.04006;175.92560;,
 506.38448;1250.04006;189.56848;,
 -447.47759;1250.04006;148.67808;,
 -447.47759;1250.04006;175.92560;,
 -506.38448;1250.04006;148.67808;,
 -506.38448;1250.04006;189.56848;,
 450.36466;76.16864;-187.92625;,
 506.38448;76.16864;-187.92625;,
 -506.38448;76.16864;-187.92625;,
 -447.47759;76.16864;-187.92625;,
 -447.47759;531.40191;148.67808;,
 -447.47759;531.40191;-187.92625;,
 450.36466;531.40191;148.67808;,
 -506.38448;531.40191;-187.92625;,
 450.36466;531.40191;-187.92625;,
 -506.38448;531.40191;148.67808;,
 506.38448;531.40191;-187.92625;,
 -506.38448;531.40191;189.56848;,
 506.38448;531.40191;148.67808;,
 -447.47759;76.16864;189.56848;,
 -447.47759;531.40191;189.56848;,
 506.38448;531.40191;189.56848;,
 450.36466;531.40191;189.56848;,
 450.36466;76.16864;189.56848;,
 -447.47759;585.24225;148.67808;,
 -447.47759;585.24225;-187.92625;,
 -506.38448;585.24225;-187.92625;,
 450.36466;585.24225;148.67808;,
 450.36466;585.24225;-187.92625;,
 -506.38448;585.24225;148.67808;,
 506.38448;585.24225;-187.92625;,
 -506.38448;585.24225;189.56848;,
 506.38448;585.24225;148.67808;,
 506.38448;585.24225;189.56848;,
 -506.38448;987.71349;-187.92625;,
 -447.47759;987.71349;-187.92625;,
 -506.38448;987.71349;148.67808;,
 -447.47759;987.71349;148.67808;,
 -506.38448;987.71349;189.56848;,
 450.36466;987.71349;148.67808;,
 -447.47759;987.71349;189.56848;,
 450.36466;987.71349;-187.92625;,
 506.38448;987.71349;-187.92625;,
 450.36466;987.71349;189.56848;,
 506.38448;987.71349;189.56848;,
 506.38448;987.71349;148.67808;,
 -506.38448;1047.11427;-187.92625;,
 -506.38448;1085.65363;-187.92625;,
 -447.47759;1085.65363;-187.92625;,
 -447.47759;1047.11427;-187.92625;,
 -506.38448;1047.11427;148.67808;,
 -447.47759;1047.11427;148.67808;,
 -506.38448;1047.11427;189.56848;,
 450.36466;1047.11427;148.67808;,
 450.36466;1047.11427;-187.92625;,
 450.36466;1085.65363;-187.92625;,
 506.38448;1085.65363;-187.92625;,
 506.38448;1047.11427;-187.92625;,
 506.38448;1047.11427;189.56848;,
 506.38448;1047.11427;148.67808;,
 506.38448;1133.88293;-159.30081;,
 450.36466;1133.88293;-159.30081;,
 450.36466;1165.93537;-103.86817;,
 506.38448;1165.93537;-103.86817;,
 -447.47759;1133.88293;-159.30081;,
 -506.38448;1133.88293;-159.30081;,
 -506.38448;1165.93537;-103.86817;,
 -447.47759;1165.93537;-103.86817;,
 -506.38448;1047.11427;-145.92049;,
 -506.38448;1047.11427;-98.13376;,
 -447.47759;1047.11427;-145.92049;,
 450.36466;1047.11427;-145.92049;,
 506.38448;1047.11427;-145.92049;,
 506.38448;1047.11427;-98.13376;,
 450.36466;1169.11125;-71.37312;,
 506.38448;1169.11125;-71.37312;,
 -506.38448;1169.11125;-71.37312;,
 -447.47759;1169.11125;-71.37312;,
 -506.38448;1047.11427;-71.37312;,
 -447.47759;1047.11427;-29.32080;,
 450.36466;1047.11427;-29.32080;,
 506.38448;1047.11427;-71.37312;,
 450.36466;1151.97150;-14.02912;,
 506.38448;1151.97150;-14.02912;,
 -506.38448;1151.97150;-14.02912;,
 -447.47759;1151.97150;-14.02912;,
 -506.38448;1047.11427;-29.32080;,
 506.38448;1047.11427;-29.32080;,
 450.36466;1128.01222;31.84624;,
 506.38448;1128.01222;31.84624;,
 -506.38448;1128.01222;31.84624;,
 -447.47759;1128.01222;31.84624;,
 -506.38448;1047.11427;31.84624;,
 -447.47759;1047.11427;68.16416;,
 450.36466;1047.11427;68.16416;,
 506.38448;1047.11427;31.84624;,
 450.36466;1127.71584;68.16416;,
 506.38448;1127.71584;68.16416;,
 -506.38448;1127.71584;68.16416;,
 -447.47759;1127.71584;68.16416;,
 -506.38448;1047.11427;68.16416;,
 506.38448;1047.11427;68.16416;,
 450.36466;1164.91887;114.03952;,
 506.38448;1164.91887;114.03952;,
 -506.38448;1164.91887;114.03952;,
 -447.47759;1164.91887;114.03952;,
 -506.38448;1047.11427;114.03936;,
 506.38448;1047.11427;114.03936;,
 -350.14336;76.16864;166.79376;,
 -350.14336;531.40191;166.79376;,
 353.03025;76.16864;166.79376;,
 353.03025;531.40191;166.79376;,
 -350.14336;987.71349;166.79376;,
 353.03025;987.71349;166.79376;;
 
 184;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,0,3,9;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,15,5,4;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;23,22,24,25;,
 4;26,27,28,29;,
 4;25,24,30,31;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;36,39,17,16;,
 4;40,20,23,41;,
 4;42,43,26,44;,
 4;41,23,25,45;,
 4;43,46,47,48;,
 4;43,48,27,26;,
 4;45,25,31,49;,
 4;48,50,51,27;,
 4;52,32,35,53;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,44,26,73;,
 4;72,73,57,56;,
 4;73,26,29,74;,
 4;73,74,58,57;,
 4;74,29,75,76;,
 4;74,76,59,58;,
 4;76,75,44,72;,
 4;76,72,56,59;,
 4;77,27,51,78;,
 4;77,78,61,60;,
 4;78,51,79,80;,
 4;78,80,62,61;,
 4;80,79,28,81;,
 4;80,81,63,62;,
 4;81,28,27,77;,
 4;81,77,60,63;,
 4;82,42,38,83;,
 4;82,83,65,64;,
 4;83,38,46,84;,
 4;83,84,66,65;,
 4;84,46,43,85;,
 4;84,85,67,66;,
 4;85,43,42,82;,
 4;85,82,64,67;,
 4;86,48,47,87;,
 4;86,87,69,68;,
 4;87,47,54,88;,
 4;87,88,70,69;,
 4;88,54,50,89;,
 4;88,89,71,70;,
 4;89,50,48,86;,
 4;89,86,68,71;,
 4;90,91,92,93;,
 4;91,94,95,92;,
 4;94,96,97,95;,
 4;98,99,40,41;,
 4;100,101,45,49;,
 4;102,45,101,103;,
 4;102,104,41,45;,
 4;103,101,100,105;,
 4;104,106,98,41;,
 4;105,100,49,107;,
 4;106,108,99,98;,
 4;107,49,55,109;,
 4;108,110,40,99;,
 4;109,55,111,112;,
 4;110,113,37,40;,
 4;113,114,115,37;,
 4;116,102,103,117;,
 4;117,103,105,118;,
 4;119,120,106,104;,
 4;118,105,107,121;,
 4;120,122,108,106;,
 4;121,107,109,123;,
 4;122,124,110,108;,
 4;124,125,113,110;,
 4;120,117,116,119;,
 4;106,120,119,104;,
 4;103,106,104,102;,
 4;117,103,102,116;,
 4;117,120,106,103;,
 4;126,127,117,118;,
 4;126,118,121,128;,
 4;127,129,116,117;,
 4;128,121,123,130;,
 4;129,131,119,116;,
 4;130,123,112,132;,
 4;131,133,120,119;,
 4;133,134,122,120;,
 4;135,114,125,136;,
 4;134,137,124,122;,
 4;136,125,124,137;,
 4;138,139,140,141;,
 4;138,141,127,126;,
 4;138,126,128,142;,
 4;141,143,129,127;,
 4;142,128,130,144;,
 4;142,144,97,96;,
 4;143,94,91,145;,
 4;144,132,95,97;,
 4;145,146,133,131;,
 4;146,147,148,149;,
 4;146,149,134,133;,
 4;135,150,93,92;,
 4;149,151,137,134;,
 4;150,136,137,151;,
 4;150,151,90,93;,
 4;133,146,145,131;,
 4;127,133,131,129;,
 4;141,127,129,143;,
 4;141,146,133,127;,
 4;152,148,147,153;,
 4;152,153,154,155;,
 4;156,140,139,157;,
 4;156,157,158,159;,
 4;157,139,138,160;,
 4;157,160,161,158;,
 4;162,141,140,156;,
 4;153,147,146,163;,
 4;164,149,148,152;,
 4;164,152,155,165;,
 4;163,146,141,162;,
 4;166,167,155,154;,
 4;168,169,159,158;,
 4;170,168,158,161;,
 4;169,171,162,159;,
 4;172,166,154,163;,
 4;167,173,165,155;,
 4;171,172,163,162;,
 4;174,175,167,166;,
 4;176,177,169,168;,
 4;178,176,168,170;,
 4;175,179,173,167;,
 4;180,181,175,174;,
 4;182,183,177,176;,
 4;184,182,176,178;,
 4;183,185,171,177;,
 4;186,180,174,172;,
 4;181,187,179,175;,
 4;185,186,172,171;,
 4;188,189,181,180;,
 4;190,191,183,182;,
 4;192,190,182,184;,
 4;189,193,187,181;,
 4;194,91,90,195;,
 4;194,195,189,188;,
 4;196,96,94,197;,
 4;196,197,191,190;,
 4;198,142,96,196;,
 4;198,196,190,192;,
 4;197,143,185,191;,
 4;145,194,188,186;,
 4;195,90,151,199;,
 4;195,199,193,189;,
 4;143,145,186,185;,
 3;162,156,159;,
 3;163,154,153;,
 3;172,174,166;,
 3;171,169,177;,
 3;185,183,191;,
 3;186,188,180;,
 3;145,91,194;,
 3;143,197,94;,
 3;135,136,150;,
 3;132,144,130;,
 3;112,123,109;,
 3;114,113,125;,
 4;200,201,112,111;,
 4;202,200,111,115;,
 4;203,202,115,114;,
 4;201,200,202,203;,
 4;201,204,132,112;,
 4;205,203,114,135;,
 4;204,201,203,205;,
 4;204,205,92,95;,
 3;92,205,135;,
 3;95,132,204;;
 
 MeshMaterialList {
  4;
  184;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.432800;0.179200;0.125600;1.000000;;
   5.000000;
   0.180000;0.180000;0.180000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.649600;0.615200;0.574400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.248000;0.166400;0.132000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.464000;0.627200;0.320000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  65;
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  -0.057241;0.000000;0.998360;,
  0.057241;0.000000;0.998360;,
  1.000000;0.000000;0.000000;,
  0.994895;-0.088322;0.048822;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.277816;-0.960634;0.000000;,
  0.265543;-0.964099;-0.000000;,
  -0.004982;0.010041;0.999937;,
  -0.751424;-0.659820;0.000000;,
  -0.004982;0.010041;-0.999937;,
  0.770112;-0.637908;-0.000000;,
  0.063996;-0.231825;0.970650;,
  -0.043112;-0.189534;0.980927;,
  0.000000;0.264633;-0.964349;,
  0.000000;0.264633;-0.964349;,
  0.091713;0.000000;0.995785;,
  -0.091713;0.000000;0.995786;,
  0.119645;0.015408;0.992697;,
  -0.121042;0.015410;0.992528;,
  -0.073440;0.013060;0.997214;,
  0.000000;0.952077;-0.305858;,
  0.000000;0.952077;-0.305858;,
  0.000000;0.711124;-0.703067;,
  0.000000;0.711124;-0.703067;,
  0.000000;0.995347;0.096358;,
  0.000000;0.995347;0.096358;,
  0.000000;0.926470;0.376368;,
  0.000000;0.970202;0.242297;,
  0.000000;0.970202;0.242297;,
  0.000000;0.943879;-0.330292;,
  0.000000;0.595541;-0.803325;,
  0.000000;0.595541;-0.803325;,
  0.114672;0.000000;0.993403;,
  -0.114672;0.000000;0.993403;,
  0.114652;0.003974;0.993398;,
  -0.114652;0.003974;0.993398;,
  0.988446;-0.132656;0.073329;,
  0.124234;-0.450043;0.884323;,
  -0.907543;-0.419959;0.000000;,
  0.988578;-0.004621;0.150637;,
  0.956283;0.253317;0.146128;,
  -0.092607;-0.357032;0.929490;,
  0.007813;-0.015752;0.999845;,
  -0.009963;0.020080;-0.999749;,
  0.939271;-0.343176;-0.000000;,
  0.049038;-0.178019;-0.982804;,
  0.096389;-0.349915;-0.931809;,
  -0.009963;0.020080;0.999749;,
  -0.043112;-0.189534;-0.980927;,
  -0.092607;-0.357032;-0.929490;,
  0.007813;-0.015752;-0.999845;,
  0.000000;0.192034;-0.981388;,
  0.000000;0.192034;-0.981388;,
  0.069950;0.013054;0.997465;,
  0.122990;0.014014;0.992309;,
  0.139546;0.026041;0.989873;,
  -0.146471;0.026048;0.988872;,
  -0.125316;0.014016;0.992018;,
  0.000000;0.376919;-0.926246;,
  0.000000;0.376919;-0.926246;,
  -0.114672;0.000000;0.993403;;
  184;
  4;0,0,0,0;,
  4;2,1,1,1;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;3,1,1,1;,
  4;3,1,1,2;,
  4;4,5,40,4;,
  4;6,6,6,6;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;6,6,6,6;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;4,4,5,4;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;7,9,9,7;,
  4;10,7,7,10;,
  4;7,7,9,9;,
  4;10,10,7,7;,
  4;15,41,41,15;,
  4;15,15,1,1;,
  4;12,42,42,12;,
  4;12,12,9,9;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;43,40,5,43;,
  4;43,43,44,44;,
  4;16,45,45,16;,
  4;16,16,46,46;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;13,0,0,13;,
  4;13,13,47,47;,
  4;14,48,48,14;,
  4;14,14,10,10;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;12,42,42,12;,
  4;12,12,9,9;,
  4;49,50,50,49;,
  4;49,49,0,0;,
  4;14,48,48,14;,
  4;14,14,10,10;,
  4;11,1,1,11;,
  4;11,11,51,51;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;52,53,53,52;,
  4;52,52,54,54;,
  4;6,6,6,6;,
  4;6,6,6,6;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;7,7,7,7;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;0,0,0,0;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;1,1,3,19;,
  4;4,4,4,4;,
  4;1,20,2,1;,
  4;4,4,4,4;,
  4;0,0,0,0;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;0,0,0,0;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;4,4,4,4;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;0,0,0,0;,
  4;1,1,19,21;,
  4;8,8,8,8;,
  4;0,0,0,0;,
  4;22,20,1,1;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;0,18,18,0;,
  4;0,0,0,0;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;0,55,56,0;,
  4;57,21,58,59;,
  4;8,8,8,8;,
  4;0,17,17,0;,
  4;0,0,0,0;,
  4;22,23,60,61;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;0,0,0,0;,
  4;26,17,17,26;,
  4;26,26,24,24;,
  4;27,18,18,27;,
  4;27,27,25,25;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;28,28,24,24;,
  4;29,29,25,25;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;30,30,28,28;,
  4;30,30,29,29;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;31,31,30,30;,
  4;32,32,30,30;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  4;33,33,31,31;,
  4;33,33,32,32;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;34,56,62,34;,
  4;34,34,33,33;,
  4;35,63,55,35;,
  4;35,35,33,33;,
  4;8,8,8,8;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;8,8,8,8;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;6,6,6,6;,
  3;4,4,4;,
  3;8,8,8;,
  3;8,8,8;,
  3;4,4,4;,
  3;4,4,4;,
  3;8,8,8;,
  3;8,8,8;,
  3;4,4,4;,
  3;22,1,23;,
  3;21,57,1;,
  3;19,1,1;,
  3;20,1,1;,
  4;36,36,19,3;,
  4;6,6,6,6;,
  4;37,64,2,20;,
  4;36,36,64,37;,
  4;36,38,21,19;,
  4;39,37,20,22;,
  4;38,36,37,39;,
  4;38,39,61,58;,
  3;61,39,22;,
  3;58,21,38;;
 }
 MeshTextureCoords {
  206;
  0.944690;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.944690;1.000000;,
  0.055310;0.000000;,
  0.055310;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.058160;0.000000;,
  0.058160;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.941840;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.941840;1.000000;,
  0.107850;0.000000;,
  0.107850;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.892150;,
  1.000000;1.000000;,
  0.944690;1.000000;,
  0.944690;0.892150;,
  0.058160;1.000000;,
  0.058160;0.892150;,
  0.944690;0.107850;,
  0.058160;0.107850;,
  0.058160;0.000000;,
  0.944690;0.000000;,
  0.000000;1.000000;,
  0.000000;0.892150;,
  0.892150;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.892150;1.000000;,
  0.892150;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.892150;1.000000;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  1.000000;0.892150;,
  0.944690;0.892150;,
  1.000000;0.107850;,
  0.058160;0.107850;,
  0.944690;1.000000;,
  0.058160;1.000000;,
  0.058160;0.892150;,
  0.000000;0.107850;,
  0.000000;0.892150;,
  0.000000;0.107850;,
  0.107850;0.000000;,
  0.107850;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  0.944690;0.000000;,
  1.000000;0.000000;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.000000;0.000000;,
  0.058160;0.000000;,
  1.000000;0.892150;,
  1.000000;1.000000;,
  0.944690;1.000000;,
  0.944690;0.892150;,
  0.058160;0.892150;,
  0.058160;1.000000;,
  0.000000;1.000000;,
  0.000000;0.892150;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  0.944690;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.058160;0.000000;,
  1.000000;0.892150;,
  1.000000;1.000000;,
  0.944690;1.000000;,
  0.944690;0.892150;,
  0.058160;0.892150;,
  0.058160;1.000000;,
  0.000000;1.000000;,
  0.000000;0.892150;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  0.944690;0.000000;,
  1.000000;0.000000;,
  0.058160;0.107850;,
  0.058160;0.000000;,
  0.000000;0.107850;,
  0.000000;0.000000;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.058160;0.107850;,
  0.058160;0.107850;,
  0.944690;0.107850;,
  0.000000;0.107850;,
  0.944690;0.107850;,
  0.000000;0.107850;,
  1.000000;0.107850;,
  0.000000;0.000000;,
  1.000000;0.107850;,
  0.058160;0.000000;,
  0.058160;0.000000;,
  1.000000;0.000000;,
  0.944690;0.000000;,
  0.944690;0.000000;,
  0.058160;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.944690;0.107850;,
  0.944690;0.107850;,
  0.000000;0.107850;,
  1.000000;0.107850;,
  0.000000;0.000000;,
  1.000000;0.107850;,
  1.000000;0.000000;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.000000;,
  0.944690;0.107850;,
  0.058160;0.000000;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.944690;0.000000;,
  1.000000;0.000000;,
  1.000000;0.107850;,
  0.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.000000;,
  0.944690;0.107850;,
  0.944690;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  1.000000;0.107850;,
  1.000000;0.000000;,
  1.000000;0.107850;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  1.000000;0.107850;,
  0.944690;0.107850;,
  1.000000;0.107850;,
  0.000000;0.107850;,
  0.058160;0.107850;,
  0.000000;0.107850;,
  1.000000;0.107850;,
  0.058160;0.000000;,
  0.058160;0.000000;,
  0.944690;0.000000;,
  0.944690;0.000000;,
  0.058160;0.000000;,
  0.944690;0.000000;;
 }
}

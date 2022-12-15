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
 119;
 0.00000;0.00000;0.00000;,
 0.60495;-0.09028;-0.90988;,
 -0.03084;0.05116;-1.09089;,
 0.00000;0.00000;0.00000;,
 1.00055;-0.26903;-0.39395;,
 0.00000;0.00000;0.00000;,
 1.00496;-0.41688;0.25985;,
 0.00000;0.00000;0.00000;,
 0.61647;-0.47729;0.80184;,
 0.00000;0.00000;0.00000;,
 -0.01653;-0.42722;1.02493;,
 0.00000;0.00000;0.00000;,
 -0.65226;-0.28572;0.84396;,
 0.00000;0.00000;0.00000;,
 -1.04794;-0.10696;0.32802;,
 0.00000;0.00000;0.00000;,
 -1.05234;0.04088;-0.32580;,
 0.00000;0.00000;0.00000;,
 -0.66381;0.10124;-0.86777;,
 0.00000;0.00000;0.00000;,
 -0.03084;0.05116;-1.09089;,
 1.10329;-0.54780;-1.79667;,
 -0.10595;-0.27878;-2.14093;,
 1.85585;-0.88786;-0.81530;,
 1.86420;-1.16907;0.42834;,
 1.12520;-1.28394;1.45922;,
 -0.07887;-1.18872;1.88357;,
 -1.28811;-0.91970;1.53933;,
 -2.04066;-0.57960;0.55795;,
 -2.04902;-0.29848;-0.68569;,
 -1.31000;-0.18351;-1.71657;,
 -0.10595;-0.27878;-2.14093;,
 1.44627;-1.32788;-2.57354;,
 -0.21810;-0.95759;-3.04736;,
 2.48205;-1.79591;-1.22279;,
 2.49363;-2.18286;0.48895;,
 1.47645;-2.34109;1.90780;,
 -0.18084;-2.20994;2.49188;,
 -1.84520;-1.83966;2.01808;,
 -2.88101;-1.37160;0.66734;,
 -2.89252;-0.98460;-1.04438;,
 -1.87541;-0.82644;-2.46329;,
 -0.21810;-0.95759;-3.04736;,
 1.60031;-2.35399;-3.16444;,
 -0.35629;-1.91868;-3.72145;,
 2.81794;-2.90417;-1.57655;,
 2.83149;-3.35916;0.43571;,
 1.63580;-3.54509;2.10370;,
 -0.31245;-3.39099;2.79033;,
 -2.26908;-2.95566;2.23332;,
 -3.48671;-2.40546;0.64544;,
 -3.50024;-1.95051;-1.36682;,
 -2.30453;-1.76455;-3.03483;,
 -0.35629;-1.91868;-3.72145;,
 1.36150;-4.87776;-3.70253;,
 -0.69577;-4.42004;-4.28820;,
 2.64182;-5.45625;-2.03291;,
 2.65609;-5.93466;0.08291;,
 1.39878;-6.13015;1.83672;,
 -0.64970;-5.96809;2.55869;,
 -2.70697;-5.51037;1.97302;,
 -3.98730;-4.93181;0.30342;,
 -4.00154;-4.45344;-1.81240;,
 -2.74428;-4.25801;-3.56624;,
 -0.69577;-4.42004;-4.28820;,
 0.91615;-7.48545;-3.97029;,
 -1.04043;-7.05018;-4.52734;,
 2.13385;-8.03567;-2.38241;,
 2.14736;-8.49064;-0.37015;,
 0.95162;-8.67659;1.29783;,
 -0.99659;-8.52242;1.98448;,
 -2.95321;-8.08710;1.42745;,
 -4.17084;-7.53697;-0.16043;,
 -4.18437;-7.08197;-2.17268;,
 -2.98868;-6.89607;-3.84068;,
 -1.04043;-7.05018;-4.52734;,
 0.49232;-8.60143;-3.75505;,
 -1.17204;-8.23117;-4.22888;,
 1.52814;-9.06954;-2.40430;,
 1.53962;-9.45652;-0.69259;,
 0.52252;-9.61473;0.72630;,
 -1.13476;-9.48355;1.31038;,
 -2.79915;-9.11328;0.83654;,
 -3.83494;-8.64522;-0.51419;,
 -3.84650;-8.25823;-2.22592;,
 -2.82936;-8.10001;-3.64480;,
 -1.17204;-8.23117;-4.22888;,
 -0.06478;-9.52145;-3.27631;,
 -1.27402;-9.25243;-3.62055;,
 0.68775;-9.86158;-2.29494;,
 0.69615;-10.14274;-1.05130;,
 -0.04285;-10.25762;-0.02041;,
 -1.24692;-10.16233;0.40393;,
 -2.45618;-9.89332;0.05968;,
 -3.20873;-9.55329;-0.92167;,
 -3.21707;-9.27211;-2.16532;,
 -2.47808;-9.15717;-3.19620;,
 -1.27402;-9.25243;-3.62055;,
 -0.70065;-10.15543;-2.58093;,
 -1.33634;-10.01389;-2.76192;,
 -0.30494;-10.33419;-2.06500;,
 -0.30055;-10.48197;-1.41117;,
 -0.68906;-10.54238;-0.86920;,
 -1.32204;-10.49233;-0.64611;,
 -1.95783;-10.35081;-0.82709;,
 -2.35345;-10.17218;-1.34303;,
 -2.35787;-10.02426;-1.99685;,
 -1.96938;-9.96384;-2.53881;,
 -1.33634;-10.01389;-2.76192;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;,
 -1.35288;-10.44118;-1.73699;;
 
 100;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 3;17,18,16;,
 3;19,20,18;,
 4;2,1,21,22;,
 4;1,4,23,21;,
 4;4,6,24,23;,
 4;6,8,25,24;,
 4;8,10,26,25;,
 4;10,12,27,26;,
 4;12,14,28,27;,
 4;14,16,29,28;,
 4;16,18,30,29;,
 4;18,20,31,30;,
 4;22,21,32,33;,
 4;21,23,34,32;,
 4;23,24,35,34;,
 4;24,25,36,35;,
 4;25,26,37,36;,
 4;26,27,38,37;,
 4;27,28,39,38;,
 4;28,29,40,39;,
 4;29,30,41,40;,
 4;30,31,42,41;,
 4;33,32,43,44;,
 4;32,34,45,43;,
 4;34,35,46,45;,
 4;35,36,47,46;,
 4;36,37,48,47;,
 4;37,38,49,48;,
 4;38,39,50,49;,
 4;39,40,51,50;,
 4;40,41,52,51;,
 4;41,42,53,52;,
 4;44,43,54,55;,
 4;43,45,56,54;,
 4;45,46,57,56;,
 4;46,47,58,57;,
 4;47,48,59,58;,
 4;48,49,60,59;,
 4;49,50,61,60;,
 4;50,51,62,61;,
 4;51,52,63,62;,
 4;52,53,64,63;,
 4;55,54,65,66;,
 4;54,56,67,65;,
 4;56,57,68,67;,
 4;57,58,69,68;,
 4;58,59,70,69;,
 4;59,60,71,70;,
 4;60,61,72,71;,
 4;61,62,73,72;,
 4;62,63,74,73;,
 4;63,64,75,74;,
 4;66,65,76,77;,
 4;65,67,78,76;,
 4;67,68,79,78;,
 4;68,69,80,79;,
 4;69,70,81,80;,
 4;70,71,82,81;,
 4;71,72,83,82;,
 4;72,73,84,83;,
 4;73,74,85,84;,
 4;74,75,86,85;,
 4;77,76,87,88;,
 4;76,78,89,87;,
 4;78,79,90,89;,
 4;79,80,91,90;,
 4;80,81,92,91;,
 4;81,82,93,92;,
 4;82,83,94,93;,
 4;83,84,95,94;,
 4;84,85,96,95;,
 4;85,86,97,96;,
 4;88,87,98,99;,
 4;87,89,100,98;,
 4;89,90,101,100;,
 4;90,91,102,101;,
 4;91,92,103,102;,
 4;92,93,104,103;,
 4;93,94,105,104;,
 4;94,95,106,105;,
 4;95,96,107,106;,
 4;96,97,108,107;,
 3;99,98,109;,
 3;98,100,110;,
 3;100,101,111;,
 3;101,102,112;,
 3;102,103,113;,
 3;103,104,114;,
 3;104,105,115;,
 3;105,106,116;,
 3;106,107,117;,
 3;107,108,118;;
 
 MeshMaterialList {
  6;
  100;
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.455200;0.800000;0.489600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.800000;0.065600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.351200;0.800000;0.542400;0.610000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  92;
  0.152279;0.964401;0.216199;,
  0.143191;0.980734;-0.132881;,
  0.340207;0.937440;-0.073929;,
  0.458602;0.884137;0.089360;,
  0.455807;0.840695;0.292357;,
  0.335644;0.822548;0.459084;,
  0.143504;0.836208;0.529305;,
  -0.050722;0.877416;0.477042;,
  -0.174663;0.931526;0.318986;,
  -0.178063;0.977567;0.112499;,
  -0.056205;0.996516;-0.061620;,
  0.116458;0.880067;-0.460348;,
  0.482905;0.803518;-0.348083;,
  0.702197;0.710672;-0.043179;,
  0.696513;0.635430;0.333313;,
  0.474152;0.603900;0.640691;,
  0.119581;0.627386;0.769472;,
  -0.240037;0.699117;0.673512;,
  -0.472669;0.794441;0.381375;,
  -0.482169;0.876071;-0.003568;,
  -0.255733;0.909053;-0.328974;,
  0.078532;0.688527;-0.720946;,
  0.567852;0.593180;-0.570685;,
  0.863343;0.477407;-0.163466;,
  0.858303;0.383306;0.341164;,
  0.561099;0.344161;0.752809;,
  0.086468;0.374135;0.923334;,
  -0.394411;0.464084;0.793137;,
  -0.706229;0.583083;0.401566;,
  -0.719972;0.684653;-0.113535;,
  -0.417788;0.725138;-0.547383;,
  0.029257;0.402423;-0.914986;,
  0.595797;0.298455;-0.745621;,
  0.945615;0.173114;-0.275398;,
  0.946022;0.073017;0.315770;,
  0.599586;0.035690;0.799514;,
  0.044256;0.074428;0.996244;,
  -0.514675;0.175062;0.839323;,
  -0.873884;0.301958;0.380983;,
  -0.887953;0.406406;-0.215347;,
  -0.540327;0.444834;-0.714261;,
  -0.009600;0.157307;-0.987503;,
  0.570918;0.053392;-0.819269;,
  0.937903;-0.071027;-0.339547;,
  0.946611;-0.168806;0.274649;,
  0.589290;-0.201027;0.782512;,
  0.009805;-0.155993;0.987709;,
  -0.570685;-0.052088;0.819515;,
  -0.937701;0.072338;0.339831;,
  -0.946455;0.170127;-0.274370;,
  -0.589140;0.202350;-0.782284;,
  -0.044178;-0.073935;-0.996284;,
  0.514827;-0.174588;-0.839328;,
  0.874089;-0.301446;-0.380919;,
  0.888179;-0.405814;0.215528;,
  0.540527;-0.444141;0.714541;,
  -0.029131;-0.401662;0.915324;,
  -0.595778;-0.297674;0.745948;,
  -0.945686;-0.172363;0.275624;,
  -0.946104;-0.072340;-0.315680;,
  -0.599610;-0.035113;-0.799521;,
  -0.086461;-0.374138;-0.923334;,
  0.394419;-0.464072;-0.793140;,
  0.706236;-0.583068;-0.401573;,
  0.719982;-0.684641;0.113543;,
  0.417788;-0.725133;0.547390;,
  -0.078535;-0.688530;0.720943;,
  -0.567848;-0.593184;0.570685;,
  -0.863343;-0.477408;0.163464;,
  -0.858304;-0.383302;-0.341164;,
  -0.561105;-0.344162;-0.752804;,
  -0.119583;-0.627387;-0.769471;,
  0.240031;-0.699112;-0.673519;,
  0.472657;-0.794445;-0.381381;,
  0.482160;-0.876076;0.003570;,
  0.255729;-0.909052;0.328979;,
  -0.116467;-0.880063;0.460352;,
  -0.482894;-0.803518;0.348098;,
  -0.702191;-0.710677;0.043190;,
  -0.696515;-0.635420;-0.333328;,
  -0.474150;-0.603897;-0.640694;,
  -0.143512;-0.836193;-0.529326;,
  0.050709;-0.877407;-0.477060;,
  0.174655;-0.931535;-0.318964;,
  0.178073;-0.977567;-0.112483;,
  0.056242;-0.996514;0.061619;,
  -0.143216;-0.980728;0.132901;,
  -0.340210;-0.937434;0.073992;,
  -0.458574;-0.884155;-0.089331;,
  -0.455807;-0.840679;-0.292401;,
  -0.335639;-0.822534;-0.459112;,
  -0.152263;-0.964403;-0.216202;;
  100;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,9,8;,
  3;0,10,9;,
  3;0,1,10;,
  4;1,2,12,11;,
  4;2,3,13,12;,
  4;3,4,14,13;,
  4;4,5,15,14;,
  4;5,6,16,15;,
  4;6,7,17,16;,
  4;7,8,18,17;,
  4;8,9,19,18;,
  4;9,10,20,19;,
  4;10,1,11,20;,
  4;11,12,22,21;,
  4;12,13,23,22;,
  4;13,14,24,23;,
  4;14,15,25,24;,
  4;15,16,26,25;,
  4;16,17,27,26;,
  4;17,18,28,27;,
  4;18,19,29,28;,
  4;19,20,30,29;,
  4;20,11,21,30;,
  4;21,22,32,31;,
  4;22,23,33,32;,
  4;23,24,34,33;,
  4;24,25,35,34;,
  4;25,26,36,35;,
  4;26,27,37,36;,
  4;27,28,38,37;,
  4;28,29,39,38;,
  4;29,30,40,39;,
  4;30,21,31,40;,
  4;31,32,42,41;,
  4;32,33,43,42;,
  4;33,34,44,43;,
  4;34,35,45,44;,
  4;35,36,46,45;,
  4;36,37,47,46;,
  4;37,38,48,47;,
  4;38,39,49,48;,
  4;39,40,50,49;,
  4;40,31,41,50;,
  4;41,42,52,51;,
  4;42,43,53,52;,
  4;43,44,54,53;,
  4;44,45,55,54;,
  4;45,46,56,55;,
  4;46,47,57,56;,
  4;47,48,58,57;,
  4;48,49,59,58;,
  4;49,50,60,59;,
  4;50,41,51,60;,
  4;51,52,62,61;,
  4;52,53,63,62;,
  4;53,54,64,63;,
  4;54,55,65,64;,
  4;55,56,66,65;,
  4;56,57,67,66;,
  4;57,58,68,67;,
  4;58,59,69,68;,
  4;59,60,70,69;,
  4;60,51,61,70;,
  4;61,62,72,71;,
  4;62,63,73,72;,
  4;63,64,74,73;,
  4;64,65,75,74;,
  4;65,66,76,75;,
  4;66,67,77,76;,
  4;67,68,78,77;,
  4;68,69,79,78;,
  4;69,70,80,79;,
  4;70,61,71,80;,
  4;71,72,82,81;,
  4;72,73,83,82;,
  4;73,74,84,83;,
  4;74,75,85,84;,
  4;75,76,86,85;,
  4;76,77,87,86;,
  4;77,78,88,87;,
  4;78,79,89,88;,
  4;79,80,90,89;,
  4;80,71,81,90;,
  3;81,82,91;,
  3;82,83,91;,
  3;83,84,91;,
  3;84,85,91;,
  3;85,86,91;,
  3;86,87,91;,
  3;87,88,91;,
  3;88,89,91;,
  3;89,90,91;,
  3;90,81,91;;
 }
 MeshTextureCoords {
  119;
  0.050000;0.000000;,
  0.100000;0.100000;,
  0.000000;0.100000;,
  0.150000;0.000000;,
  0.200000;0.100000;,
  0.250000;0.000000;,
  0.300000;0.100000;,
  0.350000;0.000000;,
  0.400000;0.100000;,
  0.450000;0.000000;,
  0.500000;0.100000;,
  0.550000;0.000000;,
  0.600000;0.100000;,
  0.650000;0.000000;,
  0.700000;0.100000;,
  0.750000;0.000000;,
  0.800000;0.100000;,
  0.850000;0.000000;,
  0.900000;0.100000;,
  0.950000;0.000000;,
  1.000000;0.100000;,
  0.100000;0.200000;,
  0.000000;0.200000;,
  0.200000;0.200000;,
  0.300000;0.200000;,
  0.400000;0.200000;,
  0.500000;0.200000;,
  0.600000;0.200000;,
  0.700000;0.200000;,
  0.800000;0.200000;,
  0.900000;0.200000;,
  1.000000;0.200000;,
  0.100000;0.300000;,
  0.000000;0.300000;,
  0.200000;0.300000;,
  0.300000;0.300000;,
  0.400000;0.300000;,
  0.500000;0.300000;,
  0.600000;0.300000;,
  0.700000;0.300000;,
  0.800000;0.300000;,
  0.900000;0.300000;,
  1.000000;0.300000;,
  0.100000;0.400000;,
  0.000000;0.400000;,
  0.200000;0.400000;,
  0.300000;0.400000;,
  0.400000;0.400000;,
  0.500000;0.400000;,
  0.600000;0.400000;,
  0.700000;0.400000;,
  0.800000;0.400000;,
  0.900000;0.400000;,
  1.000000;0.400000;,
  0.100000;0.500000;,
  0.000000;0.500000;,
  0.200000;0.500000;,
  0.300000;0.500000;,
  0.400000;0.500000;,
  0.500000;0.500000;,
  0.600000;0.500000;,
  0.700000;0.500000;,
  0.800000;0.500000;,
  0.900000;0.500000;,
  1.000000;0.500000;,
  0.100000;0.600000;,
  0.000000;0.600000;,
  0.200000;0.600000;,
  0.300000;0.600000;,
  0.400000;0.600000;,
  0.500000;0.600000;,
  0.600000;0.600000;,
  0.700000;0.600000;,
  0.800000;0.600000;,
  0.900000;0.600000;,
  1.000000;0.600000;,
  0.100000;0.700000;,
  0.000000;0.700000;,
  0.200000;0.700000;,
  0.300000;0.700000;,
  0.400000;0.700000;,
  0.500000;0.700000;,
  0.600000;0.700000;,
  0.700000;0.700000;,
  0.800000;0.700000;,
  0.900000;0.700000;,
  1.000000;0.700000;,
  0.100000;0.800000;,
  0.000000;0.800000;,
  0.200000;0.800000;,
  0.300000;0.800000;,
  0.400000;0.800000;,
  0.500000;0.800000;,
  0.600000;0.800000;,
  0.700000;0.800000;,
  0.800000;0.800000;,
  0.900000;0.800000;,
  1.000000;0.800000;,
  0.100000;0.900000;,
  0.000000;0.900000;,
  0.200000;0.900000;,
  0.300000;0.900000;,
  0.400000;0.900000;,
  0.500000;0.900000;,
  0.600000;0.900000;,
  0.700000;0.900000;,
  0.800000;0.900000;,
  0.900000;0.900000;,
  1.000000;0.900000;,
  0.050000;1.000000;,
  0.150000;1.000000;,
  0.250000;1.000000;,
  0.350000;1.000000;,
  0.450000;1.000000;,
  0.550000;1.000000;,
  0.650000;1.000000;,
  0.750000;1.000000;,
  0.850000;1.000000;,
  0.950000;1.000000;;
 }
}
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
 1.20979;0.06002;0.35413;,
 1.19277;0.22935;-0.35796;,
 0.00000;0.00000;0.00000;,
 0.78477;-0.21382;0.91729;,
 0.00000;0.00000;0.00000;,
 0.08009;-0.48752;1.11655;,
 0.00000;0.00000;0.00000;,
 -0.63513;-0.65657;0.87576;,
 0.00000;0.00000;0.00000;,
 -1.08767;-0.65640;0.28688;,
 0.00000;0.00000;0.00000;,
 -1.10468;-0.48698;-0.42512;,
 0.00000;0.00000;0.00000;,
 -0.67970;-0.21317;-0.98837;,
 0.00000;0.00000;0.00000;,
 0.02501;0.06051;-1.18759;,
 0.00000;0.00000;0.00000;,
 0.74022;0.22957;-0.94677;,
 0.00000;0.00000;0.00000;,
 1.19277;0.22935;-0.35796;,
 2.40626;-0.31289;0.60252;,
 2.37391;0.00922;-0.75185;,
 1.59787;-0.83378;1.67381;,
 0.25745;-1.35445;2.05277;,
 -1.10295;-1.67599;1.59469;,
 -1.96371;-1.67563;0.47457;,
 -1.99611;-1.35353;-0.87975;,
 -1.18772;-0.83259;-1.95104;,
 0.15271;-0.31199;-2.33001;,
 1.51311;0.00960;-1.87192;,
 2.37391;0.00922;-0.75185;,
 3.47233;-1.08235;0.72088;,
 3.42779;-0.63894;-1.14322;,
 2.35965;-1.79919;2.19534;,
 0.51474;-2.51579;2.71704;,
 -1.35767;-2.95841;2.08652;,
 -2.54245;-2.95786;0.54479;,
 -2.58703;-2.51452;-1.31926;,
 -1.47438;-1.79758;-2.79377;,
 0.37055;-1.08099;-3.31536;,
 2.24300;-0.63839;-2.68492;,
 3.42779;-0.63894;-1.14322;,
 4.30362;-2.17279;0.69765;,
 4.25128;-1.65161;-1.49376;,
 2.99554;-3.01553;2.43097;,
 0.82674;-3.85795;3.04418;,
 -1.37441;-4.37828;2.30306;,
 -2.76719;-4.37768;0.49063;,
 -2.81959;-3.85646;-1.70073;,
 -1.51158;-3.01370;-3.43408;,
 0.65726;-2.17127;-4.04733;,
 2.85847;-1.65095;-3.30617;,
 4.25128;-1.65161;-1.49376;,
 5.13968;-5.02076;0.27419;,
 5.08467;-4.47269;-2.02996;,
 3.76430;-5.90687;2.09678;,
 1.48388;-6.79269;2.74157;,
 -0.83057;-7.33969;1.96221;,
 -2.29503;-7.33912;0.05656;,
 -2.35010;-6.79104;-2.24753;,
 -0.97480;-5.90486;-4.07017;,
 1.30565;-5.01914;-4.71492;,
 3.62020;-4.47215;-3.93567;,
 5.08467;-4.47269;-2.02996;,
 5.62179;-8.01578;-0.28290;,
 5.56941;-7.49460;-2.47428;,
 4.31368;-8.85859;1.45054;,
 2.14483;-9.70097;2.06370;,
 -0.05634;-10.22130;1.32252;,
 -1.44910;-10.22067;-0.48982;,
 -1.50150;-9.69950;-2.68122;,
 -0.19345;-8.85676;-4.41459;,
 1.97539;-8.01433;-5.02784;,
 4.17661;-7.49405;-4.28671;,
 5.56941;-7.49460;-2.47428;,
 5.38920;-9.35779;-0.66432;,
 5.34465;-8.91443;-2.52841;,
 4.27648;-10.07473;0.81022;,
 2.43155;-10.79130;1.33179;,
 0.55911;-11.23393;0.70139;,
 -0.62566;-11.23335;-0.84034;,
 -0.67021;-10.79002;-2.70444;,
 0.44245;-10.07306;-4.17896;,
 2.28739;-9.35648;-4.70067;,
 4.15984;-8.91383;-4.07018;,
 5.34465;-8.91443;-2.52841;,
 4.79823;-10.51883;-1.10384;,
 4.76593;-10.19670;-2.45821;,
 3.98980;-11.03975;-0.03256;,
 2.64941;-11.56039;0.34643;,
 1.28898;-11.88189;-0.11162;,
 0.42819;-11.88152;-1.23175;,
 0.39583;-11.55936;-2.58610;,
 1.20423;-11.03846;-3.65737;,
 2.54467;-10.51789;-4.03636;,
 3.90510;-10.19632;-3.57832;,
 4.76593;-10.19670;-2.45821;,
 3.90679;-11.38534;-1.55847;,
 3.88976;-11.21591;-2.27046;,
 3.48178;-11.65916;-0.99521;,
 2.77708;-11.93283;-0.79596;,
 2.06187;-12.10188;-1.03679;,
 1.60933;-12.10171;-1.62562;,
 1.59231;-11.93226;-2.33768;,
 2.01733;-11.65852;-2.90088;,
 2.72201;-11.38476;-3.10016;,
 3.43723;-11.21569;-2.85934;,
 3.88976;-11.21591;-2.27046;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;,
 2.80209;-11.87229;-1.98357;;
 
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
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
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
  -0.294982;0.928274;0.226480;,
  0.032163;0.992592;0.117158;,
  0.035720;0.940962;0.336624;,
  -0.079260;0.862816;0.499266;,
  -0.262723;0.792993;0.549672;,
  -0.448330;0.756289;0.476473;,
  -0.571091;0.762271;0.304626;,
  -0.583342;0.806891;0.092948;,
  -0.476740;0.875466;-0.079239;,
  -0.289892;0.946296;-0.143132;,
  -0.093828;0.993197;-0.068969;,
  0.355880;0.934500;-0.007656;,
  0.355991;0.843587;0.402035;,
  0.134698;0.704063;0.697246;,
  -0.203703;0.583475;0.786169;,
  -0.544121;0.521818;0.656991;,
  -0.772838;0.532023;0.345937;,
  -0.794231;0.605959;-0.044837;,
  -0.592284;0.719190;-0.363269;,
  -0.245298;0.839957;-0.484047;,
  0.119649;0.927917;-0.353064;,
  0.625321;0.770196;-0.125589;,
  0.621210;0.661024;0.420887;,
  0.318167;0.490183;0.811474;,
  -0.132761;0.342003;0.930273;,
  -0.586503;0.262690;0.766164;,
  -0.894894;0.270830;0.354705;,
  -0.917445;0.360495;-0.168340;,
  -0.637945;0.498966;-0.586566;,
  -0.176446;0.645758;-0.742875;,
  0.307066;0.756164;-0.577863;,
  0.834196;0.499188;-0.234369;,
  0.833413;0.387622;0.393919;,
  0.479312;0.213547;0.851268;,
  -0.047199;0.057841;0.997210;,
  -0.580001;-0.032879;0.813952;,
  -0.942588;-0.029535;0.332650;,
  -0.957729;0.070815;-0.278820;,
  -0.620183;0.225396;-0.751378;,
  -0.088995;0.379713;-0.920814;,
  0.462624;0.488595;-0.739766;,
  0.919869;0.258174;-0.295275;,
  0.926623;0.152275;0.343776;,
  0.567165;-0.009609;0.823548;,
  0.019998;-0.160673;0.986805;,
  -0.540200;-0.256100;0.801621;,
  -0.920146;-0.256869;0.295550;,
  -0.926958;-0.151008;-0.343431;,
  -0.567560;0.010816;-0.823261;,
  -0.020385;0.161871;-0.986601;,
  0.539876;0.257357;-0.801437;,
  0.942595;0.030028;-0.332584;,
  0.957713;-0.070344;0.278993;,
  0.620082;-0.224906;0.751608;,
  0.088799;-0.379145;0.921066;,
  -0.462915;-0.487917;0.740032;,
  -0.834575;-0.498439;0.234614;,
  -0.833823;-0.386884;-0.393775;,
  -0.479639;-0.212869;-0.851254;,
  0.047002;-0.057232;-0.997254;,
  0.579929;0.033422;-0.813981;,
  0.894894;-0.270836;-0.354700;,
  0.917438;-0.360503;0.168361;,
  0.637933;-0.498960;0.586583;,
  0.176435;-0.645734;0.742898;,
  -0.307085;-0.756143;0.577880;,
  -0.625334;-0.770183;0.125598;,
  -0.621208;-0.661030;-0.420880;,
  -0.318165;-0.490197;-0.811466;,
  0.132748;-0.342016;-0.930270;,
  0.586491;-0.262695;-0.766172;,
  0.772817;-0.532053;-0.345939;,
  0.794213;-0.605982;0.044851;,
  0.592281;-0.719193;0.363269;,
  0.245299;-0.839961;0.484040;,
  -0.119657;-0.927917;0.353062;,
  -0.355886;-0.934498;0.007637;,
  -0.355994;-0.843580;-0.402045;,
  -0.134712;-0.704072;-0.697235;,
  0.203690;-0.583489;-0.786162;,
  0.544102;-0.521841;-0.656990;,
  0.571048;-0.762297;-0.304644;,
  0.583312;-0.806911;-0.092958;,
  0.476729;-0.875473;0.079225;,
  0.289886;-0.946302;0.143106;,
  0.093838;-0.993195;0.068975;,
  -0.032153;-0.992587;-0.117205;,
  -0.035758;-0.940951;-0.336648;,
  0.079240;-0.862836;-0.499234;,
  0.262745;-0.792994;-0.549659;,
  0.448314;-0.756304;-0.476466;,
  0.294981;-0.928271;-0.226492;;
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
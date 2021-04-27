a=1;
b=-2;
c=3;
d=2;
[X,Y] = meshgrid([-5:0.1:5]);
[K,M] = meshgrid([-5:0.1:5]);
[H,U] = meshgrid([-5:0.1:5]);

Z = 3* exp(-((X-a).^2+(Y-b).^2).^0.5);
P = 2*exp(-(((K-c).^2)/3+((M-d).^2)/0.9).^0.5);
G = 5* exp(-(((H).^2)/2+((U).^2)/3).^0.5);
figure (1);
plot3 (X,Y,Z,'g', K,M,P,'r');
% figure (2);
% mesh(X,Y,Z);
% figure (3);
% mesh(K,M,P);
figure (4);
mesh(X,Y,Z+P+G);
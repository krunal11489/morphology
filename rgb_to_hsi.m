clear;
clc;
close all;
I = imread('football.jpg');
figure,imshow(I);
[m n l]=size(I);
for i=1:m;
    for j=1:n;
        r1=I(i,j,1);g1=I(i,j,2);b1=I(i,j,3);
        r1=double(r1);g1=double(g1);b1=double(b1);
        r=r1;g=g1;b=b1;
        c1=(r-g)+(r-b);c2=(r-b)*(g-b);c3=(r-g)*(r-g);
        c6=c3+(c2);
        c6=double(c6);
        c4=sqrt(c6);
        c5=0.5*(c1);
        c=(c5)/(c4);c=double(c);
        t=acosd(c);
        if(b<=g)
            h=t;
        else
            h=(360-t);
        end
        a1=min(r,g);a2=min(a1,b);       
        a3=(r+g+b);
        s=1-((1/a3)*a2);
        in=((r+g+b)/3);
%         H(i,j)=uint8((h/360)*255);
%         S(i,j)=uint8(s*255);
%         In(i,j)=uint8(in*255);
         J(i,j,1)=h/360;J(i,j,2)=s;J(i,j,3)=in;
    end
end
J1=im2double(J);
figure,imshow(J1);
%  figure,imshow(H);
% figure,imshow(S);
% figure,imshow(In);
% imwrite(H,'hue.tif');
% imwrite(S,'sat.tif');
% imwrite(In,'int.tif');

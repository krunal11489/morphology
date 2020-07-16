clear;
a=imread('football.jpg');
a1=rgb2hsv(a);
%imshow(a1);
h=double(a1(:,:,1));
s=double(a1(:,:,2));
v=double(a1(:,:,3));
%imshow(h),figure;imshow(s),figure;imshow(v);
 
H=h.*360;
[m,n]=size(H);
for i=1:m
    for j=1:n
if (H(i,j)>=0 && H(i,j)<120)
    
    b(i,j)=v(i,j).*(1-s(i,j));
    r1(i,j)= cosd(H(i,j))./cosd(60-H(i,j));
    r2(i,j)=1+s(i,j).*r1(i,j);
    r(i,j)=v(i,j).*r2(i,j);
    
    g(i,j)=3.*v(i,j)-(r(i,j)+b(i,j));
end
if (H(i,j)>=120 && H(i,j)<240)
    H(i,j)=H(i,j)-120;
    
    r(i,j)=v(i,j).*(1-s(i,j));
    r1(i,j)= cosd(H(i,j))./cosd(60-H(i,j));
    r2(i,j)=1+s(i,j).*r1(i,j);
    g(i,j)=v(i,j).*r2(i,j);
    
    b(i,j)=3.*v(i,j)-(r(i,j)+g(i,j));
end
if (H(i,j)>=240 && H(i,j)<360)
    H(i,j)=H(i,j)-240;
    
    g(i,j)=v(i,j).*(1-s(i,j));
    r1(i,j)= cosd(H(i,j))./cosd(60-H(i,j));
    r2(i,j)=1+s(i,j).*r1(i,j);
    b(i,j)=v(i,j).*r2(i,j);
    
    r(i,j)=3.*v(i,j)-(g(i,j)+b(i,j));
 
end
    end
end
f(:,:,1)=r;
f(:,:,2)=g;
f(:,:,3)=b;
imshow((r)),figure;imshow(g),figure;imshow(b);
figure;imshow((f));

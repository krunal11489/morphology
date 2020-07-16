I1 = imread('football.jpg');
J1 = rgb2gray(I1);
I2 = imread('greens.jpg');
J2 = rgb2gray(I2);
[m1,n1]=size(J1);
[m2,n2]=size(J2);
m3=max(m1,m2);
n3=max(n1,n2);
J1(m1:m3,n1:n3)=0;
J2(m2:m3,n2:n3)=0;
for i=1:m3
    for j=1:n3
            c(i,j)=J1(i,j)+J2(i,j);
    end 
end
figure,imshow(uint8(c));
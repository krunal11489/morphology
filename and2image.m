clear;
I1 = imread('lor22d.jpg');
J1 = rgb2gray(I1);
I2 = imread('lor34d.jpg');
J2 = rgb2gray(I2);
[m1,n1]=size(J1);
[m2,n2]=size(J2);
m3=max(m1,m2);
n3=max(n1,n2);
J1(m1:m3,n1:n3)=0;
J2(m2:m3,n2:n3)=0;
for i=1:m3
    for j=1:n3
        a=dec2bin(J1(i,j));
        b=dec2bin(J2(i,j));
        [n m]=size(a);
        if(m<8)
            a1(1:8-m)=48;
        end    
        a1(8-m+1:8)=a(1:m);
        a1=a1-48;
        [p l]=size(b);
        if(l<8)
            b2(1:8-l)=48;
        end    
        b2(8-l+1:8)=b(1:l);
        b2=b2-48;
        c=a1.*b2;
        c1=0;
        for x=0:7
            c1=c1+2^x.*c(8-x);
        end    
        J3(i,j)=uint8(c1);

    end
end
figure,imshow(J3);
clc;
clear all;
close all;
I=imread('coins.png');
imshow(I);
[m,n]=size(I);
[counts,x]=imhist(I);
stem(x,counts);
p=counts/(m*n);
%k=85;
mg=0;
for i=1:256
    mg=mg+(i-1)*p(i);
end

p1(1:256)=0;
m1(1:256)=0;

for k=1:256
    for i=1:k
        p1(k)=p1(k)+p(i);
    end
end
for k=1:256
    for i=1:k
        m1(k)=m1(k)+(((i-1)*p(i))/p1(k));
    end
end
    %m1(k)=m1(k)./p1(k);
for k=1:256
    temp1=((mg*p1(k))-m1(k))^2;
    temp2=p1(k)*(1-p1(k));
    sigma(k)=temp1/temp2;
end

[kmax,ki]=max(sigma);

for i=1:m
    for j=1:n
        if(I(i,j)>ki)
            J(i,j)=true;
        else
            J(i,j)=false;
        end
    end
end
imshow(J);
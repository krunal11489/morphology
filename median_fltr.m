close all;
clear;
J = imread('circuit.tif');
%J = rgb2gray(K);
figure,imshow(J);
title('original image');
[m,n]=size(J);
J1(m+2,n+2)=0;
J2(m,n)=0;
for i=1:m+2;
    for j=1:n+2;
        if(i>1 && i<m+2)
            if(j>1 && j<n+2)
                J1(i,j)=J(i-1,j-1);
            end
        end
    end
end
for i=2:m+1;
    for j=2:n+1;
        w(1,10)=0;x=0;
        for k=-1:1;
            for l=-1:1;
                x=x+1;
                w(1,x)=J1(i+k,j+l);             
            end
        end
        for o=1:9;
            for x=1:9;
                if(w(1,x)<w(1,1+x))
                    temp=w(1,x);
                    w(1,x)=w(1,1+x);
                    w(1,1+x)=temp;
                end
            end
        end
        J2(i-1,j-1)=w(1,5);
    end
end
J3=uint8(J2);
figure,imshow(J3);
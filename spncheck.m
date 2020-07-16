%salt & pepper noise
v=imread('onion.png');
[m n r]=size(v);
b=imnoise1('saltpepper',m,n,1,5);
v1=rgb2gray(a);
for i=1:m
    for j=1:n
        if b(i,j)==0
            c(i,j)=0;
        end
        if b(i,j)==1
            c(i,j)=255;
        end
       if ~(b(i,j)==1 | b(i,j) == 0)
            c(i,j)=v1(i,j);
        end
    end
end

imshow(v1);
title('original image');
figure;
subplot(1,2,1);
imshow(c);
title('noisy image due to saltpepper');


a1(1,1:n+2)=zeros(1,n+2);
    for i=2:m+1
        a1(i,1:n+2)=[0 v1(i-1,1:n) 0];
    end
    a1(i+1,1:n+2)=zeros(1,n+2);
for i=2:m+1
    for j=2:n+1
        
            a2(1:9)=[a1(i-1,j-1:j+1) a1(i,j-1:j+1) a1(i+1,j-1:j+1)];
            
        for k=1:9
            for l=k:9
                if(a2(l)<a2(k))
                    a3=a2(k);
                    a2(k)=a2(l);
                    a2(l)=a3;
                end
            end
        end
        a4(i-1,j-1)=a2(5);
    end
end
 subplot(1,2,2);
imshow(uint8(a4));
title('filtered image using medianfilter');
                



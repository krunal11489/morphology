clear;
a=imread('latter.png');
[m n r]=size(a);
a1=rgb2gray(a);
 
for i=1:m
    for j=1:n
        if a(i,j)<128
            a1(i,j)=0;
        else
            a1(i,j)=255;
        end
    end
end
 
%line detection        
lines=0;
a2=0;
for i=1:m
    for j=1:50
        if a1(i,j)==255;
            a2=a2+1;
        else
            a3(i,1:n)=0;
        end
        
    end
    if a2>=49
        a3(i,1:n)=255;
        
    end
    a2=0;
end
for i=1:m-1
    if a3(i,1)==0 && a3(i+1,1)==255
        a2=a2+1;
    end
    
end
char=0;
lines=a2
a2=0;
words=0;
%words
mask=uint8(ones(5,5));
for i=4:m-4
    for j=4:n-4
        a4(i,j)=(1/25)*sum(sum(((a1(i-2:i+2,j-2:j+2)).*(mask))));
        
        if a4(i,j)<255
            a5(i,j)=0;
        else
            a5(i,j)=a4(i,j);
        end
    end
end
for i=10:12:m-4
    for j=1:n-5
        if a5(i,j)==255 
             a2=a2+1;
        end
          if a5(i,j)==255 && a5(i,j+1)==0
              if a2>=6
                  words=words+1;
              end
              a2=0;
          end
          
    end
    words=words+1;
    a2=0;
end
words

%label connected components
%%
clear;

% a1=imread('connected.jpg');
% [m n r]=size(a1);
% a2=rgb2gray(a1);
a2=imread('rgn_fill.tif');
[m n]=size(a2);
k=1;j=1;
label(1,1)=1;
a(1,1:n+2)=0;
a(2:m+1,1:n+2)=[zeros(m,1) a2(1:m,1:n) zeros(m,1)];
a(m+2,1:n+2)=0;
label(1:m+2,1:n+2)=0;
    for i=1:m+2
        
        if a(i,1)==255
          if a(i-1,1)==255 
             
              label(i,1)=label(i-1,1);
             
          else
              label(i,1)=max(max(label))+1;
              
          end
        end
    end
    
    for j=2:n+2
        for i=1:m+2
            
            if a(i,j)==255
                if a(i-1,j)==255
                    if a(i,j-1)==255
                        label(i,j)=min(label(i-1,j),label(i,j-1));
                        if label(i-1,j) ~= label(i,j-1)
                        table(k,1:2)=[label(i,j-1) label(i-1,j)];
                        k=k+1;
                        end
                        
                        
                    else
                        label(i,j)=label(i-1,j);
                    end
                end
                if a(i,j-1)==255
                    label(i,j)=label(i,j-1);
                end

                if a(i-1,j) ~=255 && a(i,j-1)~=255
                label(i,j)=max(max(label))+1;
                end
                
                    
                
            end
        end
    end
    
  %%
  %%
  %warshall's algorithm
 m1=size(table);
 m2=max(max(table));
  tabler(1:m2,1:m2)=0;
 tabler(1,1)=1;
  for i=1:m1
      tabler(table(i,1),table(i,2))=1;
  end
  
  b=tabler;
 [m1 n1]=size(b);
b1=b;
j=1;
for j=1:n1
for i=1:n1
    if b1(i,j)>=1
        for k=1:n1
            b1(i,k)=b1(i,k)+b1(j,k);                
        end
    end
end
end
for i=1:n1
    for j=1:n1
       if b1(i,j)>1
            b1(i,j)=1;
       end
    end
end


%%
%final label calculation
for i=m1:-1:1
    for j=i:m1
    if b1(i,j)==1
        [r c]=find(table(:,2)==j);
        [r1 r2]=size(r);
        [c1 c2]=size(c);
            for i1=1:r1
                
                table(r(i1),3)=i;
                
            end
    end
    end
end

for i=1:m
    for j=1:n
        [r c]=find(table(:,2)==label(i,j));
        [r1 r2]=size(r);
        [c1 c2]=size(c);
            for i1=r1:-1:1
                
                label(i,j)=table(i1,3);
                
            end
    end
end

label=uint8(label);
for i=1:m
    for j=1:n
        
       if label(i,j)==1
           label1(i,j,1:3)=[255  0 0];
       end
       if label(i,j)==2
           label1(i,j,1:3)=[0 255 0];
       end
       
       if label (i,j)>10 && label(i,j)<max(max(label))
           label1(i,j,1:3)=[0 255 255];
       end
       if  label(i,j)==max(max(label))
           label1(i,j,1:3)=[255 255 255];
       end
    end
end
            
imshow(label1);
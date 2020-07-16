function[N,p]=hole_points(L,z)
%%counting the no. of pixels in components
t=max(max(L));
c(1,1:t+1)=0;
[m,n]=size(L);
M(m+2,n+2)=0;
N(m,n)=0;bc=0;p=0;
for i=1:m
    for j=1:n
        x=L(i,j);
        if(x~=0)
            c(x)=c(x)+1;
        end
    end
end
%% r is index,identifying back ground components
r=0;
% z indicates approximate no. pixels in holes
% bc holds component no. of back ground
for j=1:t+1
    if(c(1,j)>z)
        r=r+1;
        bc(r)=j;
    end
end
% removing back ground components
for i=1:m
    for j=1:n
        x=L(i,j);
        match=0;
        for k=1:length(bc)
            if(x==bc(k))
                match=1;
                break;
            end
        end
        if(match==1)
            L(i,j)=0;
        end
    end
end
% removing border
for i=1:m
    for j=1:n
        M(i+1,j+1)=L(i,j);
    end
end
%% finding a point in each hole
s=0;r=0;
for i=2:m+1
    for j=2:n+1
        x=M(i,j);
        if(x~=0)
            match=0;
            for k=1:r
                if(x==s(k))
                    match=1;
                    break;
                end
            end
            if(match==0)
                q=0;
                for i1=-1:1
                    for j1=-1:1
                        if(x~=M(i+i1,j+j1))
                            q=1;
                            break;
                        end
                    end
                    if(q==1)
                        break;
                    end
                end
                if(q==0)
                    r=r+1;
                    s(r)=x;
                    p(r,1)=i;
                    p(r,2)=j;
                end
            end
        end
    end
end                  
for i=1:length(p)
    N(p(i,1),p(i,2))=1;
end
figure,imshow(L);
figure,imshow(N);
end
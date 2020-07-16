function [f]=imnoise1(type,m,n,a,b)
if strcmp(type,'gaussian')
    f=a+(b*randn(m,n));
end
if strcmp(type,'exponential')
    f=-(1/a)*(log(1-rand(m,n)));
end
if strcmp(type,'lognormal')
    f=a*exp(b*rand(m,n));
end
if strcmp(type,'erlang')
    f=0;
    for k=a:b
        f=f+(1/a)*log(1-rand(m,n));
    end
end
if strcmp(type,'saltpepper')
        f(1:m,1:n)=0.5;
        x=rand(m,n);
        
        c=find(x<.02);
        f(c)=0;
        d=find(x>.97);
        f(d)=1;
end

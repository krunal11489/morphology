function[K]=closing(I,se)
J=dil_m(I,se);
K=ero_m(J,se);
end
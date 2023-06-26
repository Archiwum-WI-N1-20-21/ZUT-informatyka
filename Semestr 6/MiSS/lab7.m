clear;
close all;

load('lab7N_data2')

Xu = data2(:,1:2);
Zu = data2(:,3:6);

Xu = Xu';
Zu = Zu';
Rs = Xu*Zu';
Ps = Zu*Zu';
A1 = Rs * Ps ^-1

Xu2 = data2(:,1:2);
Zu2 = data2(:,3:6);
Xu2 = Xu2';
Zu2 = Zu2';
Zu2 = [Zu; Zu2.^2];
Rs2 = Xu2*Zu2';
Ps2 = Zu2*Zu2';
A12 = Rs2 * Ps2 ^-1

load('lab7N_data1')
Xt = data1(:,1:2);
Zt = data1(:,3:6);
xpp = Zt * A1(1,:)';
errX = mean((Xt(:,1)- xpp).^2);
ypp = Zt * A1(2,:)';
errY = mean((Xt(:,2)-ypp).^2)
err1 = (errX + errY)/2

Zt = [Zt,Zt.^2];
xpp2 = Zt * A12(1,:)';
errX2 = mean((Xt(:,1)- xpp2).^2);
ypp2 = Zt * A12(2,:)';
errY2 = mean((Xt(:,2)-ypp2).^2)
err12 = (errX2 + errY2)/2
ddx = @(xp,yp,x,y) [xp,yp,x,y]*A1(1,:)';
ddy = @(xp,yp,x,y) [xp,yp,x,y]*A1(2,:)';

x = [60];
y = [0];
xp = [0];
yp = [0];
xpp = [ddx(xp(end),yp(end),x(end),y(end))];
ypp = [ddy(xp(end),yp(end),x(end),y(end))];

h = 2^(-8);
STOP = 500;
for t = h:h:STOP

    x(end+1) = x(end) + xp(end) * h;

    y(end+1) = y(end) + yp(end) * h;

    xp(end+1) = xp(end) + xpp(end) * h;

    yp(end+1) = yp(end) + ypp(end) * h;

    xpp(end+1) = ddx(xp(end),yp(end),x(end),y(end));

    ypp(end+1) = ddy(xp(end),yp(end),x(end),y(end));
end

figure(name = 'Euler');
plot(x,y)
figure(name = 'Plik')
plot(Zt(:,3),Zt(:,4))
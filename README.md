# mcmc-lmc

Langevin Monte Carlo method

[![Build Status](https://travis-ci.org/hiroyam/mcmc-lmc.svg?branch=master)](https://travis-ci.org/hiroyam/mcmc-lmc)

---

#### これは何？

MCMCのランジュバン方程式を用いたモンテカルロ法のC++によるフルスクラッチです。

関数h(w)と逆温度betaが与えられたとき、exp(-beta * h(w))に比例する確率分布に従う乱数を発生させる手法です。

ランジュバン方程式 
```
w(t+e) = w(t) - e * beta * delta(h(w)) + g(e)
```
は、あるポテンシャル h 下でのブラウン運動を記述する確率微分方程式ですが、この確率微分方程式はフォッカープランク方程式を用いて解くことができ、定常解をもつ場合、
```
exp(-beta * h(x))
```
の形になることが知られています。よってオイラー法でこの確率微分方程式を離散化してサンプリングを行うことで、目的の確率分布に従う乱数を得ることができます。

##### 動作サンプル

ガウス分布に従う乱数を発生させてみた例です。
![](images/plot1.png)


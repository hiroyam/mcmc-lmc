# mcmc-lmc

Langevin Monte Carlo method

[![Build Status](https://travis-ci.org/hiroyam/mcmc-lmc.svg?branch=master)](https://travis-ci.org/hiroyam/mcmc-lmc)

---

#### これは何？

MCMCのランジュバンモンテカルロ法のC++によるフルスクラッチです。

関数h(w)と逆温度betaが与えられたとき、exp(-beta * h(w))に比例する確率分布に従う乱数を発生させる手法です。

ランジュバン方程式はあるポテンシャル下でのブラウン運動を記述する確率微分方程式ですが、この方程式が定常分布をもつ場合、exp(-U(x))の形になることが知られています。この確率微分方程式をオイラー法で離散化してサンプリングを行うことで、目的の確率分布に従う乱数を得ることができます。フォッカープランク方程式を用いてランジュバン方程式を解くと、収束する確率分布が目的の確率分布と一致することを示すことができます。

##### 動作サンプル

ガウス分布に従う乱数を発生させてみた例です。
![](images/plot1.png)


# NTP_clock_HT16K33
used library: https://werner.rothschopf.net/201909_arduino_ht16k33.htm

articles:
- NTP clock: https://nicuflorica.blogspot.com/2023/01/ceas-ntp-pe-afisaj-led-din-4-caractere.html
- DHT22 thermometer/hygrometer: https://nicuflorica.blogspot.com/2023/01/termometruhigrometru-cu-dht2211-pe.html
- NTP clock with DHT22 thermometer/hygrometer: https://nicuflorica.blogspot.com/2023/01/ceas-ntp-si-termometruhigrometru-senzor.html
- animated NTP clock with DHT22 thermometer/hygrometer: https://nicuflorica.blogspot.com/2023/01/ceas-animat-ntp-si-termometruhigrometru.html

![schematic](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEgr_YnHnno8pCx-pcHoUiS-cVsLEkjbbGgnNZ7J5fZ2UlhMpTY6VFXQ2RzO3nWbASA3qgY6GxkUPs-ycOJtYxHUZmmqVvaarbtMA9Y3RF7uXT0FTADsg5VjkdznbghFyj29m6IAw1edqebZtrvPVw4PiLZYBfjAE0Zsl8ahGjIjFj3obR59C5MM_nyRJw/s320/NTP_clock_DST_HT16K33_14segm_sch1.png)
![real](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEi55dWEpozl0mAVSMEoM1RcOlEuth0UpCrFJWsT3hr2Q5NrEf5zs2mOAOGNh9U1QH_cRGHzLaZCwRhMVU1H1A9lA60xj4uJS8bEcY-WyDqY5WAx676dyzqOi9UH69LxAo_j_hpGUn0vh0OPXsM3lB05ov2ZwYEckIeQYlyBWkGzlQCwdaY4C_x3G-bfWQ/w200-h150/montaj_test_1.jpg)
![1](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEgRIZYzrJw9G1AQoJMUWfjGJQUKLeWaGA0WW3rrwBSsIgAWe1vNVeCMTtO5CdmVk85C3FDBFrXyRjC5dRHSWNpQvkm_-AS0vnw5b2NBi8UIZrkL3trpf2Cz7Q38BBCqOgx0r1P31CyZfk6Td6_emmnE2J8_6PU7K_ojQQucggqGZ7cAcvIGZoppXhjjEw/w200-h150/ora_vara.jpg)
![2](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEgVhEqN4xZOrlgH6q24BSpKRi0_yDcUEU8QnkPmfzJmUbneT7kSMRwbALoPxB1ON-NzuazvWrJ82G_iJ6AIfgBR1_ISfyHZ9B3ALmSIQzbUJ1rzF7J61jigVDFr0dUkM2A8Zp9RFnK-NJgyKQ3UIFwBGE3ed4TlxJjPDep0081VvC_PSjiP-ThqgKGeBg/w200-h150/ora_iarna.jpg)

![dHT schematic](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhnwYYXMEE-21ox-0hu9X8wWhlvDYZRWI3V3vJb61FDB1AiTFH9npga9iqnzM_E5Zfah1vseaDVsOhIXIMBqzczWNMhAlhWDy-fmATYNu94WB6DQmE6ODgHPRid4LVg6Ogu_0Px36h10QulLH46DCU_2KTvN6u6a0j1k5BF_gt5ldhsmwVrTiKxQ9ha3w/w200-h98/Wemos_D1_DHT_HT16K33_14segm_test1_sch.png)
![temerature](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhfiuoXq3ilSYlNQbna9F82yTJOp5Pss88oO0pYzkmg2L00M4FJIYrdsqZ4siZ5YVr8FOpq_AN2nIuTEavInfLQbddElPm7DAjCQM3Qk9DnaUpVZMKv4KSPJ_oYePSTFoH7tsfyPIo8dB9_d60u2JkoUGVjq7H9E8UHTPW9Qj1JU8LC5b_b808TeWgqeg/w200-h150/DHT_plus_25C.jpg)
![humidity](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhOCMPsiyge1QGfCRNds7vPsHA_UPCLuHfoW4XBRFJrnpmNaX9k0aWCeKBT5toBmlla9WCqqPSvYpK297QuzntJ1lpYQGKX_2p_KVToMEanLepo4YmKNV0jhFgPdLlZdofeZtVrEISoIQLflMDdYZVrQ_hv-zHATZX-pfBDTKDy61lp1PFDLqq-7Uas5w/w200-h150/DHT_47lasuta.jpg)

![luni](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEj_xNINJl7W5--cXbPHKqWFlhm74BP9W8WG8jfEeb_vO2qtYrJj-aIQUup3OJQWyP99NJo2U6RwolBji851CnRycA-zelo5FV0eF0p5RlLz69lz6mKEEU8E_r8aBOpP78Ue_U8qMtAWFaRJUsLdZAGW6-fVBzUbiwZIXXMY2uDCr4Oao10s_vRb4X42sw/w200-h127/ceas_NTP_meteo_08.png) 
![Monday1](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjzm8SyRP5RAAj4EUpoNikb_7eDITiq2GhHwutqsgFi42ZJfflSjRMznwr79T_aClk81VJQDIHthoegHmZrqeqxa5p-Kczw93X7GCyXo88EM3QfF5V6atqLqwZppcPh7mjKVVSeJmqtq0cVukeICh9Uf0uYiN-pmjPq4OTRW6mpOP_aMFAzI-a4TK2pDA/w200-h132/ceas_NTP_meteo_02.png)
![Monday2](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEgrDPYgmezAeJ6ZAx75sJSL9vqOicTno1abMSoZo8yEPh_LzjgRBlsPDV3Mvb2qSZVHzDo79RkNIivnGx42Pi2pq0Mys1D1H10BYf_H9GO9NBBe2htJ1wBGEpcOdULU5u2Paej8aIrRuEuy_QH9_Q_JZJatKufr9GjeTmKX7gjVZ24S1LyoqECoWCvnMQ/w200-h129/ceas_NTP_meteo_03.png)



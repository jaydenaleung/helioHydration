# Helio Hydration - 3-Stage SODIS-Enhancing Water Bottle
Three-stage solar water disinfection (SODIS)-enhancing low-cost water bottle for NGO distribution to underserved and impoverished areas globally.

picture of entire cad model

## Overview

This is a custom-designed water bottle to enhance solar water disinfection, a process where people utilize the sun's UV rays to kill bacteria in contaminated water, especially in places without access to clean water. The goal of this project is to design an efficient device that NGOs can buy and distribute to crisis areas around the world. The three stages are fiber membrane filtration, SODIS enhancement via clearer plastic materials, reflection, and heat-trapping, and indication/readiness tracking.

**Total time spent: 25.5 hours**

## Why I Created This Project

This project was created with a team for the Conrad Challenge: Water Challenge (though we decided not to submit it in the end). However, all the work for this Blueprint project was entirely my own - the team helped with other areas of the research and project. When brainstorming, we wanted to create a project that would have a 'wow' factor for Conrad Challenge judges, a real impact on the world and global issues, and a technically challenging aspect. After conducting much research around the field, we settled on this idea because we saw that SODIS relied too much on having perfectly sunny weather and non-turbid water. Indication was also an issue since people didn't know when it was truly disinfected.

## How It Works & Implementation

The mechanical structure is comprised of a body, a filter, and an indicator with its housing. The body is parabolic 100mm from the ground, and cylindrical until it reaches a height of ~227mm. Its largest diameter is 120mm. The filter mechanism is a clamp with a twist cap for the membrane fiber filter. The indicator uses the DS18B20 temperature sensor in conjunction with the GUVA-S12SD to calculate log reductions of E. coli.

Using the OneWire and DallasTemperature Arduino libraries, both the measured voltage from the UV photodiode sensor and the Celsius temperature from the temperature are gleaned. The following theoretical function calculates the number of log reductions at a specific time:

picture of function

For the Arduino MCU, this function is used (using a discrete delta t):

picture of function

I quite enjoyed applying the volume revolution and bacterial decay formulas I learned from AP Calculus BC this year. I've never really had a project where my class knowledge helped me so much. See the journal for more details.

## Bill of Materials (BOM)

| Name | Quantity | Price (per part) | Link |
|---|---|---|---|
| GUVA-S12SD UV Sensor Photodiode | 1 | $1.76 | https://www.aliexpress.us/item/3256806350705812.html |
| DS18B20 Temperature Sensor | 1 | $0.2328 | https://jlcpcb.com/partdetail/MSKSEMI-DS18B20MS/C5379069 |
| Ceramic Capacitor SMD | 2 | $0.0007 | https://jlcpcb.com/partdetail/1907-0402CG220J500NT/C1555 |
| Electrolytic Capacitor SMD | 2 | $0.0332 | https://jlcpcb.com/partdetail/14236-CL31A106KBHNNNE/C13585 |
| Probe Housing | 1 | $0.3170 | https://www.aliexpress.us/item/3256807782132862.html |
| Epoxy resin | ~1 mL | $0.01 | https://www.walmart.com/ip/Epoxy-Resin-1-Gallon-Kit-Art-Resin-for-DIY-Jewelry-Tabletops-Crystal-Clear-High-Performance-Resin-Epoxy/5478464246?wmlspartner=imp_27795 |
| Membrane fiber filter | 1 | $0.29 | https://grupovoces.com/products/47mm-glass-fiber-filters-advantec-gc-90-100-pk-advantec |
| Clarified polypropylene (PP) | ~7.5 g | $0.0075 | Would need to contact a factory or ODM. Price taken from internet averages. |
| Total |  |  | $3.75/bottle |

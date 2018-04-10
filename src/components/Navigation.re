module Link = Gatsby.Link;

[@bs.module] external style : Js.t({..}) = "./navigation.module.scss";

open Utils;

let component = ReasonReact.statelessComponent("Navigation");

type navigationLocation =
  | Header
  | Footer;

let make = (~pathName, ~navigationLocation=Header, _children) => {
  ...component,
  render: _self => {
    let isHomePage = pathName == "/";
    let rootClassName =
      switch (navigationLocation) {
      | Header => style##root_header
      | Footer => style##root_footer
      };
    /* we dont need the activeClassName in the footer so check for it */
    let activeClassName =
      navigationLocation == Header ? style##link_active : "";
    /* Use link style for tickets link in the footer */
    <nav className=rootClassName>
      /* (
           componentOrNull(
             ! isHomePage,
             <Link to_="/" className=style##link_home>
               <div className=style##logo> (s("LINSTAVER.COM")) </div>
             </Link>,
             /* <img src=Assets.logo alt="Home" className=style##logo /> */
           )
         ) */

        <ul className=style##list>
          <li className=style##listItem>
            <Link to_="/" className=style##link activeClassName>
              (s("Home"))
            </Link>
          </li>
          <li className=style##listItem>
            <Link to_="/about/" className=style##link activeClassName>
              (s("About"))
            </Link>
          </li>
          <li className=style##listItem>
            <Link to_="/contact/" className=style##link activeClassName>
              (s("Contact Us"))
            </Link>
          </li>
        </ul>
      </nav>;
  },
};
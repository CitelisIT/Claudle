import React, { useState } from "react";
import { Dialog } from "@headlessui/react";
import { UserCircleIcon, LoginIcon } from "@heroicons/react/outline";
import { Link } from "react-router-dom";
import axios from "axios";
import { useForm, SubmitHandler } from "react-hook-form";

type Inputs = {
  username: string;
  password: string;
};

interface Props {
  loginOpen: boolean;
  setLoginOpen: React.Dispatch<React.SetStateAction<boolean>>;
  setPopupOpen: React.Dispatch<React.SetStateAction<boolean>>;
}

export default function LoginPopup({
  loginOpen,
  setLoginOpen,
  setPopupOpen,
}: Props) {
  const [loginError, setLoginError] = useState<boolean>(false);
  const {
    register,
    handleSubmit,
    reset,
    formState: { errors },
  } = useForm<Inputs>();
  const onSubmit: SubmitHandler<Inputs> = (data) => {
    setLoginError(false);
    axios
      .post("/api/login", {
        username: data.username,
        password: data.password,
      })
      .then((response) => {
        if (response.status === 200) {
          sessionStorage.setItem("loggedin", "true");
          reset();
          setLoginOpen(false);
        }
      })
      .catch((error) => {
        setLoginError(true);
        console.log(error);
      });
  };
  return (
    <Dialog
      open={loginOpen}
      onClose={() => {
        setPopupOpen(false);
        setLoginOpen(false);
      }}
      unmount={true}
      className="fixed inset-0 w-10/12 p-4 m-auto text-gray-200 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl mg:p-8 lg:w-5/12 mx-1/2 h-fit"
    >
      <Dialog.Overlay />
      <div className="flex flex-col justify-center w-full gap-4 p-6 md:gap-12 md:p-16 flex-center">
        <Dialog.Title className="flex flex-col items-center justify-center gap-2 m-2 md:m=4 md:gap-4">
          <UserCircleIcon className="w-10 h-10 lg:h-12 lg:w-12" />
          <span className="text-base font-semibold md:text-lg lg:text-xl ">
            Connexion
          </span>
        </Dialog.Title>
        <Dialog.Description as="div" className="w-full">
          <form
            onSubmit={handleSubmit(onSubmit)}
            className="flex flex-col items-start justify-center w-full gap-8"
          >
            <fieldset className="w-full">
              <label
                htmlFor="username-input"
                className="text-sm font-medium lg:text-xl md:text-lg"
              >
                Nom d'utilisateur
              </label>
              <input
                type="text"
                {...register("username", { required: true })}
                id="username-input"
                className="w-full p-2 py-2 my-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
              />
              {errors.username ? (
                <p className="form-error">
                  Veuillez entrer un nom d'utilisateur
                </p>
              ) : (
                <></>
              )}
            </fieldset>
            <fieldset className="w-full">
              <label
                htmlFor="pwd-input"
                className="text-sm font-medium lg:text-xl md:text-lg"
              >
                Mot de passe
              </label>
              <input
                type="password"
                {...register("password", { required: true })}
                id="pwd-input"
                className="w-full p-2 py-2 my-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
              />
              {errors.password ? (
                <p className="form-error">Veuillez entrer un mot de passe</p>
              ) : (
                <></>
              )}
            </fieldset>
                {loginError ? (
                  <p className="form-error w-full flex justify-center items-center text-center">Nom ou mot de passe incorect</p>
                ) : (
                  <></>
                )}
            <div className="flex items-center justify-between w-full">
              <Link
                onClick={() => setLoginOpen(false)}
                to="/register"
                className="text-sm text-gray-200 md:text-lg lg:text-xl hover:underline hover:underline-offset-4"
              >
                Créer un compte
              </Link>
              <button
                onClick={() => {
                  setPopupOpen(false);
                  handleSubmit(onSubmit);
                }}
                className="button--green"
              >
                <LoginIcon className="button__icon" />
                Se connecter
              </button>
            </div>
          </form>
        </Dialog.Description>
      </div>
    </Dialog>
  );
}
